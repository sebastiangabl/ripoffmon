/*
 * Level.cpp
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#include "Level.h"
#include "utils/File.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Level::Level(unsigned short i) {
  id = i;
  data = 0;
}

Level::~Level() {
  delete data;
}

bool Level::load(const char* fname) {
  File f;
  if (!f.open(fname, fstream::in)) {
    return false;
  }
  // Set dimensions
  unsigned short width = f.read<unsigned short>();
  unsigned short height = f.read<unsigned short>();

  data = new LevelData(width, height);

  // Neighbours
  for (unsigned i = 0; i < 4; i++) {
    neighbour[i].id = f.read<unsigned short>();
    neighbour[i].offset = f.read<short>();
  }
  // Movement data
  for (unsigned i = 0; i < (unsigned) width * (unsigned) height; i++) {
    data->movement[i % width][i / width] = f.read<byte>();
    data->floors[i % width][i / width] = f.read<byte>();
    f.read<byte>();
    f.read<byte>();
  }
  f.close();
  return true;
}

void Level::draw(RenderTarget& rt, RenderStates rs) const {
  VertexArray va(Quads, data->width * data->height * 4);
  for (unsigned i = 0; i < (unsigned) data->width * (unsigned) data->height; i++) {
    va[i * 4 + 0].position = Vector2f(i % data->width, i / data->width) * 24.f;
    va[i * 4 + 1].position = Vector2f(i % data->width, i / data->width + 1) * 24.f;
    va[i * 4 + 2].position = Vector2f(i % data->width + 1, i / data->width + 1) * 24.f;
    va[i * 4 + 3].position = Vector2f(i % data->width + 1, i / data->width) * 24.f;

    byte m = data->movement[i % data->width][i / data->width];
    byte f = data->floors[i % data->width][i / data->width] & ~LevelData::SEPERATE;
    bool merged = (f & (f - 1));
    byte f2 = log2(f);

    va[i * 4 + 0].color = va[i * 4 + 0].color = va[i * 4 + 1].color = va[i * 4 + 2].color = va[i * 4 + 3].color =
        m != LevelData::BLOCKED ?
            (merged ? Color::White : Color(100 + f2 * 20, 100 + f2 * 20, 100 + f2 * 20)) : Color::White;

    va[i * 4 + 0].texCoords = Vector2f(24 * m, 0);
    va[i * 4 + 1].texCoords = Vector2f(24 * m, 24);
    va[i * 4 + 2].texCoords = Vector2f(24 * m + 24, 24);
    va[i * 4 + 3].texCoords = Vector2f(24 * m + 24, 0);
  }
  rt.draw(va, rs);
}
