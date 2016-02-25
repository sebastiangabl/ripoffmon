/*
 * TileSet.cpp
 *
 *  Created on: 25. Feb. 2016
 *      Author: Sebastian
 */

#include "TileSet.h"
#include <iostream>

using namespace std;
using namespace sf;

TileSet::TileSet() {
  flags = 0;
  tile_size = 24;
  loaded = false;
}

TileSet::~TileSet() {
  delete[] flags;
}

bool TileSet::loadFromFile(const char* fname) {
  if (texture.loadFromFile(fname)) {
    // TODO: Load flags
    flags = new Uint8[texture.getSize().x * texture.getSize().y];
    loaded = true;
  }
  return loaded;
}

Vector2u TileSet::getTileCoords(Uint16 index) {
  if (!loaded) {
    return Vector2u();
  }
  unsigned w = texture.getSize().x / tile_size;
  return Vector2u((index % w) * tile_size, (index / w) * tile_size);
}
