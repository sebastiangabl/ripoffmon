/*
 * MusicLoop.cpp
 *
 *  Created on: 06. März 2016
 *      Author: Sebastian
 */

#include "MusicLoop.h"

#include <SFML/System/Time.hpp>
#include <climits>
#include <iostream>

using namespace std;
using namespace sf;

MusicLoop::MusicLoop() {
  start_point = 0;
  end_point = UINT_MAX;
  playing = false;
  second_pos = false;
}

MusicLoop::~MusicLoop() {
  stop();
}

bool MusicLoop::openFromFile(const char* fname, unsigned start, unsigned end) {
  stop();
  bool l = music[0].openFromFile(fname);
  music[1].openFromFile(fname);
  start_point = start;
  end_point = end;
  playing = false;
  second_pos = false;
  return l;
}

void MusicLoop::play() {
  playing = true;
  loop_thread = thread([=] {
    while (playing) {
      if (music[second_pos].getPlayingOffset() >= milliseconds(end_point)
          || music[second_pos].getStatus() != Music::Playing) {
        if (music[!second_pos].getStatus() != Music::Playing) {
          music[!second_pos].play();
        }
        if (music[second_pos].getStatus() != Music::Playing) {
          music[second_pos].play();
          music[second_pos].pause();
          music[second_pos].setPlayingOffset(milliseconds(start_point));
          second_pos = !second_pos;
          this_thread::yield();
        }
      } else if (music[second_pos].getPlayingOffset() < milliseconds(end_point - 500)) {
        this_thread::yield();
      }
    }
  });
}

void MusicLoop::stop() {
  if (playing) {
    playing = false;
    loop_thread.join();
    music[0].stop();
    music[1].stop();
  }
}

float MusicLoop::getVolume() {
  return music[0].getVolume();
}

void MusicLoop::setVolume(float vol) {
  music[0].setVolume(vol);
  music[1].setVolume(vol);
}
