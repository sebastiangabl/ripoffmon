/*
 * LevelData.cpp
 *
 *  Created on: 23. Feb. 2016
 *      Author: Sebastian
 */

#include "LevelData.h"

LevelData::LevelData(unsigned short w, unsigned short h) {
  width = w;
  height = h;
  movement = new Uint8*[width];
  floors = new Uint8*[width];
  tiles_back = new Uint8*[width];
  tiles_front = new Uint8*[width];
  for (unsigned i = 0; i < width; i++) {
    movement[i] = new Uint8[height];
    floors[i] = new Uint8[height];
    tiles_back[i] = new Uint8[height];
    tiles_front[i] = new Uint8[height];
  }
}

LevelData::~LevelData() {
  for (unsigned i = 0; i < width; i++) {
    delete[] movement[i];
    delete[] floors[i];
    delete[] tiles_back[i];
    delete[] tiles_front[i];
  }
  delete[] movement;
  delete[] floors;
  delete[] tiles_back;
  delete[] tiles_front;
}
