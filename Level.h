/*
 * Level.h
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include <string>
#include <vector>
#include "Entity.h"
#include "LevelData.h"
#include "TileSet.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/VertexArray.hpp>

using std::string;
using std::vector;
using sf::RenderTexture;
using sf::VertexArray;

class Level {
  private:
    void setVertexArrays(unsigned);
    void renderOutsideTexture(Uint16*, Uint16*);
  public:
    static TileSet debug_tiles, tiles;

    class Neighbour {
      public:
        enum Direction {
          RIGHT = 0, TOP, LEFT, BOTTOM
        };
        unsigned short id;
        short offset;
        Neighbour(unsigned short i = 0, short off = 0) : id(i), offset(off) {}
    };
    // Rendering stuff
    RenderTexture texture_debug, texture_back, texture_front, texture_outside;
    VertexArray va_debug, va_back, va_front;

    // General level stuff
    bool loaded;
    Uint16 id;
    LevelData* data;
    vector<Entity*> entities;
    Neighbour neighbour[4];

    Level(unsigned short);
    ~Level();

    bool load(const char*);
    void save(const char*);

    void render();
};

#endif /* LEVEL_H_ */
