/*
 * MusicLoop.cpp
 *
 *  Created on: 06. März 2016
 *      Author: Sebastian
 */

#include "MusicLoop.h"

#include <SFML/System.hpp>
#include <map>
#include <string>

#include "Utils/File.h"
#include "Utils/StringConverter.h"

using namespace std;
using namespace sf;

MusicLoop::MusicLoop() {
  m_loopBegin = 0;
  m_loopEnd = 0;
  m_loopCurrent = 0;
  m_fading = false;
  m_valid = false;
}

MusicLoop::~MusicLoop() {
  // We must stop before destroying the file
  stopFading();
  if (m_valid) {
    stop();
  }
}

void MusicLoop::stopFading() {
  m_fading = false;
  if (m_fading_thread.joinable()) {
    m_fading_thread.join();
  }
}

bool MusicLoop::openFromFile(const char* fname) {
  stopFading();
  if (m_valid) {
    stop();
  }
  if (!m_file.openFromFile(fname)) {
    m_valid = false;
    return false;
  }

  // Resize the internal buffer so that it can contain 1 second of audio samples
  m_samples.resize(m_file.getSampleRate() * m_file.getChannelCount());

  // Initialize the stream
  SoundStream::initialize(m_file.getChannelCount(), m_file.getSampleRate());

  setLoop(true);
  map<string, string> comments = File::readVorbisComments(fname);
  Time t_start = milliseconds(stringToType<unsigned>(comments["START"]));
  Time t_end = milliseconds(stringToType<unsigned>(comments["END"]));
  setLoopPoints(t_start, t_end);
  m_valid = true;
  return true;
}

void MusicLoop::setLoopPoints(Time begin, Time end) {
  std::size_t sampleCount = m_file.getSampleCount();

  // Reset to playing whole stream
  if (begin == end) {
    m_loopBegin = 0;
    m_loopEnd = sampleCount;
    return;
  }

  unsigned int sampleRate = getSampleRate();
  unsigned int channelCount = getChannelCount();

  begin = microseconds(max(begin.asMicroseconds(), 0ll));
  end = microseconds(max(end.asMicroseconds(), 0ll));

  Uint64 loopBegin = static_cast<Uint64>(begin.asSeconds() * sampleRate * channelCount);
  Uint64 loopEnd = static_cast<Uint64>(end.asSeconds() * sampleRate * channelCount);

  loopBegin = min(loopBegin, static_cast<Uint64>(sampleCount));
  loopEnd = min(loopEnd, static_cast<Uint64>(sampleCount));

  if (!loopEnd)
    loopEnd = sampleCount;

  loopBegin -= loopBegin % channelCount;
  loopEnd -= loopEnd % channelCount;

  m_loopBegin = loopBegin;
  m_loopEnd = loopEnd;
}

bool MusicLoop::onGetData(Chunk& data) {
  Lock lock(m_mutex);

  // Fill the chunk parameters
  data.samples = &m_samples[0];
  data.sampleCount = static_cast<std::size_t>(m_file.read(&m_samples[0], m_samples.size()));

  if (!data.sampleCount) {
    // Check if we have reached the end of the audio file
    return data.sampleCount == m_samples.size();
  }

  // Standard non-looping case
  if (m_loopBegin == m_loopEnd || !getLoop()) {
    m_loopCurrent += data.sampleCount;

    // Check if we have reached the end of the audio file
    return data.sampleCount == m_samples.size();
  }

  // We are looping

  // Check for a loop transition
  if (m_loopCurrent + data.sampleCount > m_loopEnd) {
    std::size_t endSampleCount = std::min(static_cast<std::size_t>(m_loopEnd - m_loopCurrent), data.sampleCount);
    std::size_t beginSampleCount = m_samples.size() - endSampleCount;

    // Jump back to the beginning of the sequence
    m_file.seek(m_loopBegin);

    // Fill the rest of the buffer with the data at the beginning
    beginSampleCount = static_cast<std::size_t>(m_file.read(&m_samples[endSampleCount], beginSampleCount));

    data.sampleCount = endSampleCount + beginSampleCount;
    m_loopCurrent = m_loopBegin + beginSampleCount;
  } else {
    m_loopCurrent += data.sampleCount;
  }

  return data.sampleCount == m_samples.size();
}

void MusicLoop::onSeek(Time timeOffset) {
  Lock lock(m_mutex);

  Uint64 sampleOffset = static_cast<Uint64>(timeOffset.asSeconds() * getSampleRate() * getChannelCount());
  sampleOffset -= sampleOffset % getChannelCount();

  m_loopCurrent = sampleOffset;
  m_file.seek(sampleOffset);
}

void MusicLoop::fadeOut(Time time, bool p) {
  if (!m_valid) {
    return;
  }
  stopFading();
  if (time == Time::Zero) {
    stop();
    return;
  }
  m_fading = true;
  m_fading_thread = thread([&] {
    float m = getVolume();
    float volume = 1;
    Clock c;
    while (m_fading && volume > 0) {
      volume -= c.restart().asSeconds() / time.asSeconds();
      setVolume(max(0.f, volume * m));
    }
    if (p) {
      pause();
    } else {
      stop();
    }
    setVolume(m);
  });
}

void MusicLoop::fadeIn(Time time, float m) {
  if (!m_valid) {
    return;
  }
  stopFading();
  if (time == Time::Zero) {
    play();
    return;
  }
  m_fading = true;
  m_fading_thread = thread([&] {
    float volume = 0;
    play();
    Clock c;
    while (m_fading && volume < 1) {
      volume += c.restart().asSeconds() / time.asSeconds();
      setVolume(min(100.f, volume * m));
    }
  });
}
