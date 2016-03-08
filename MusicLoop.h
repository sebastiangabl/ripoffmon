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
#include <vector>

using sf::InputSoundFile;
using sf::Time;
using sf::Mutex;
using sf::Uint64;
using std::vector;

class MusicLoop: public sf::SoundStream {
  private:
    InputSoundFile m_file;        ///< The streamed music file
    Time m_duration;    ///< Music duration
    vector<sf::Int16> m_samples;     ///< Temporary buffer of samples
    Mutex m_mutex;       ///< Mutex protecting the data
    Uint64 m_loopBegin;   ///< First sample position
    Uint64 m_loopEnd;     ///< Last sample position
    Uint64 m_loopCurrent; ///< Current sample position

  protected:
    virtual bool onGetData(Chunk&);
    virtual void onSeek(Time);

  public:
    MusicLoop(const char*);
    ~MusicLoop();

    sf::Time getLoopBegin();
    sf::Time getLoopEnd();

    void setLoopPoints(Time, Time);

    void fadeOut(Time);
    void fadeIn(Time);
};
#endif /* MUSICLOOP_H_ */
