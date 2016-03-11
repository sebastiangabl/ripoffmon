/*
 * MusicLoop.h
 *
 *  Created on: 06. März 2016
 *      Author: Sebastian
 */

#ifndef MUSICLOOP_H_
#define MUSICLOOP_H_

#include <SFML/Audio/InputSoundFile.hpp>
#include <SFML/Audio/SoundStream.hpp>
#include <SFML/Config.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Time.hpp>
#include <thread>
#include <vector>

using sf::InputSoundFile;
using sf::Time;
using sf::Mutex;
using sf::Uint64;
using sf::Uint8;
using std::vector;
using std::thread;

class MusicLoop: public sf::SoundStream {
  private:
    InputSoundFile m_file;
    Time m_duration;
    vector<sf::Int16> m_samples;
    Mutex m_mutex;
    Uint64 m_loopBegin;
    Uint64 m_loopEnd;
    Uint64 m_loopCurrent;
    thread m_fading_thread;
    bool m_fading;
    bool m_valid;

    void stopFading();

  protected:
    virtual bool onGetData(Chunk&);
    virtual void onSeek(Time);

  public:
    MusicLoop();
    ~MusicLoop();

    bool openFromFile(const char*);

    void setLoopPoints(Time, Time);

    void fadeOut(Time, bool = false);
    void fadeIn(Time, float = 100);
};
#endif /* MUSICLOOP_H_ */
