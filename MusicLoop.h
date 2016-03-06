/*
 * MusicLoop.h
 *
 *  Created on: 06. März 2016
 *      Author: Sebastian
 */

#ifndef MUSICLOOP_H_
#define MUSICLOOP_H_

#include <thread>
#include <SFML/Config.hpp>
#include <SFML/Audio/Music.hpp>

using std::thread;
using sf::Uint8;
using sf::Music;

class MusicLoop {
  private:
    Music music[2];
    unsigned start_point, end_point;
    bool playing, second_pos;
    thread loop_thread;
  public:
    MusicLoop();
    ~MusicLoop();
    bool openFromFile(const char*, unsigned = 0, unsigned = 0);
    void play();
    void stop();
    float getVolume();
    void setVolume(float);
};

#endif /* MUSICLOOP_H_ */
