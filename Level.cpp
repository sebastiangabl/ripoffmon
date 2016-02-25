/*
 * Level.cpp
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#include "Level.h"
#include "utils/File.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace sf;

TileSet Level::debug_tiles, Level::tiles;

void Level::setVertexArrays(unsigned i) {
  unsigned x = i % data->width;
  unsigned y = i / data->width;

  va_debug[i * 4 + 0].position = va_back[i * 4 + 0].position = va_front[i * 4 + 0].position = Vector2f(x, y) * 24.f;
  va_debug[i * 4 + 1].position = va_back[i * 4 + 1].position = va_front[i * 4 + 1].position = Vector2f(x, y + 1) * 24.f;
  va_debug[i * 4 + 2].position = va_back[i * 4 + 2].position = va_front[i * 4 + 2].position = Vector2f(x + 1, y + 1)
      * 24.f;
  va_debug[i * 4 + 3].position = va_back[i * 4 + 3].position = va_front[i * 4 + 3].position = Vector2f(x + 1, y) * 24.f;

  // Debug
  Uint8 m = data->movement[x][y];
  Uint8 f = data->floors[x][y] & ~LevelData::SEPERATE;
  bool merged = (f & (f - 1));
  Uint8 f2 = log2(f);

  va_debug[i * 4 + 0].color = va_debug[i * 4 + 0].color = va_debug[i * 4 + 1].color = va_debug[i * 4 + 2].color =
      va_debug[i * 4 + 3].color =
          m != LevelData::BLOCKED ?
              (merged ? Color::White : Color(100 + f2 * 20, 100 + f2 * 20, 100 + f2 * 20)) : Color::White;

  Vector2u tile = debug_tiles.getTileCoords(m);
  va_debug[i * 4 + 0].texCoords = Vector2f(tile.x, tile.y);
  va_debug[i * 4 + 1].texCoords = Vector2f(tile.x, tile.y + debug_tiles.tile_size);
  va_debug[i * 4 + 2].texCoords = Vector2f(tile.x + debug_tiles.tile_size, tile.y + debug_tiles.tile_size);
  va_debug[i * 4 + 3].texCoords = Vector2f(tile.x + debug_tiles.tile_size, tile.y);

  // Back
  tile = tiles.getTileCoords(data->tiles_back[x][y]);
  va_back[i * 4 + 0].texCoords = Vector2f(tile.x, tile.y);
  va_back[i * 4 + 1].texCoords = Vector2f(tile.x, tile.y + tiles.tile_size);
  va_back[i * 4 + 2].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y + tiles.tile_size);
  va_back[i * 4 + 3].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y);

  // Front
  tile = tiles.getTileCoords(data->tiles_front[x][y]);
  va_front[i * 4 + 0].texCoords = Vector2f(tile.x, tile.y);
  va_front[i * 4 + 1].texCoords = Vector2f(tile.x, tile.y + tiles.tile_size);
  va_front[i * 4 + 2].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y + tiles.tile_size);
  va_front[i * 4 + 3].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y);
}

void Level::renderOutsideTexture(Uint16* back, Uint16* front) {
  texture_outside.create(tiles.tile_size * 2, tiles.tile_size * 2);
  VertexArray va_back(Quads, 2 * 2 * 4);
  VertexArray va_front(Quads, 2 * 2 * 4);
  for (unsigned i = 0; i < 4; i++) {
    unsigned x = i % 2;
    unsigned y = i / 2;

    va_back[i * 4 + 0].position = va_front[i * 4 + 0].position = Vector2f(x, y) * 24.f;
    va_back[i * 4 + 1].position = va_front[i * 4 + 1].position = Vector2f(x, y + 1) * 24.f;
    va_back[i * 4 + 2].position = va_front[i * 4 + 2].position = Vector2f(x + 1, y + 1) * 24.f;
    va_back[i * 4 + 3].position = va_front[i * 4 + 3].position = Vector2f(x + 1, y) * 24.f;

    Vector2u tile = debug_tiles.getTileCoords(back[i]);
    va_back[i * 4 + 0].texCoords = Vector2f(tile.x, tile.y);
    va_back[i * 4 + 1].texCoords = Vector2f(tile.x, tile.y + tiles.tile_size);
    va_back[i * 4 + 2].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y + tiles.tile_size);
    va_back[i * 4 + 3].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y);

    tile = debug_tiles.getTileCoords(front[i]);
    va_front[i * 4 + 0].texCoords = Vector2f(tile.x, tile.y);
    va_front[i * 4 + 1].texCoords = Vector2f(tile.x, tile.y + tiles.tile_size);
    va_front[i * 4 + 2].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y + tiles.tile_size);
    va_front[i * 4 + 3].texCoords = Vector2f(tile.x + tiles.tile_size, tile.y);
  }
  texture_outside.clear(Color::Black);
  texture_outside.draw(va_back, &tiles.texture);
  texture_outside.draw(va_front, &tiles.texture);
  texture_outside.display();
  texture_outside.setRepeated(true);
}

Level::Level(unsigned short i) {
  loaded = false;
  id = i;
  data = 0;
}

Level::~Level() {
  delete data;
}

bool Level::load(const char* fname) {
  File f;
  if (!f.open(fname, fstream::in | fstream::binary)) {
    return false;
  }
  // Set dimensions
  Uint16 width = f.read<Uint16>();
  Uint16 height = f.read<Uint16>();

  data = new LevelData(width, height);

  texture_debug.create(width * 24, height * 24);
  texture_back.create(width * 24, height * 24);
  texture_front.create(width * 24, height * 24);
  va_debug = VertexArray(Quads, data->width * data->height * 4);
  va_back = VertexArray(Quads, data->width * data->height * 4);
  va_front = VertexArray(Quads, data->width * data->height * 4);

  // Neighbours
  for (unsigned i = 0; i < 4; i++) {
    neighbour[i].id = f.read<Uint16>();
    neighbour[i].offset = f.read<short>();
  }

  // Data
  for (unsigned i = 0; i < (unsigned) width * (unsigned) height; i++) {
    data->movement[i % width][i / width] = f.read<Uint8>();
    data->floors[i % width][i / width] = f.read<Uint8>();
    data->tiles_back[i % width][i / width] = f.read<Uint16>();
    data->tiles_front[i % width][i / width] = f.read<Uint16>();
    setVertexArrays(i);
  }

  // Outside Tiles
  Uint16 o_back[4], o_front[4];
  for (unsigned i = 0; i < 4; i++) {
    o_back[i] = f.read<Uint16>();
    o_front[i] = f.read<Uint16>();
  }

  // Entities
  while (!f.eof()) {
    unsigned etype = f.read<Uint8>();
    cout << "Entity with type " << etype << endl;
    switch (etype) {
    // TODO
    }
  }

  f.close();
  loaded = true;

  sort(entities.begin(), entities.end(), Entity::compare);
  renderOutsideTexture(o_back, o_front);

  return true;
}

void Level::render() {
  if (!loaded) {
    return;
  }
  texture_debug.clear(Color::Magenta);
  texture_debug.draw(va_debug, &debug_tiles.texture);
  texture_debug.display();

  texture_back.clear(Color::Magenta);
  texture_back.draw(va_back, &tiles.texture);
  texture_back.display();

  texture_front.clear(Color::Transparent);
  texture_front.draw(va_front, &tiles.texture);
  texture_front.display();
}
