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
  movement = new byte*[width];
  floors = new byte*[width];
  tiles = new byte*[width];
  flags = new byte*[width];
  for (unsigned i = 0; i < width; i++) {
    movement[i] = new byte[height];
    floors[i] = new byte[height];
    tiles[i] = new byte[height];
    flags[i] = new byte[height];
  }
}

LevelData::~LevelData() {
  for (unsigned i = 0; i < width; i++) {
    delete[] movement[i];
    delete[] floors[i];
    delete[] tiles[i];
    delete[] flags[i];
  }
  delete[] movement;
  delete[] floors;
  delete[] tiles;
  delete[] flags;
}
