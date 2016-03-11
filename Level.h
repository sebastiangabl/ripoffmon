/*
 * Level.h
 *
 *  Created on: 03. Feb. 2016
 *      Author: Sebastian
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include <SFML/Config.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

#include "Entity.h"
#include "LevelData.h"
#include "TileSet.h"

using std::string;
using std::vector;
using sf::Clock;
using sf::RenderTexture;
using sf::VertexArray;

class Level {
  private:
    void setVertexArrays(unsigned);
    void renderOutsideTexture(Uint16*, Uint16*);
  public:
    static TileSet debug_tiles;

    class Neighbour {
      public:
        enum Direction {
          RIGHT = 0, TOP, LEFT, BOTTOM
        };
        Uint16 id;
        short offset;
        Neighbour(unsigned short i = 0, short off = 0) : id(i), offset(off) {}
    };
    // Rendering stuff
    Clock animation_clock;
    vector<unsigned> animated_back, animated_front;
    RenderTexture texture_debug, texture_back, texture_front, texture_outside;
    VertexArray va_debug, va_back, va_front;

    // General level stuff
    bool loaded;
    LevelData* data;
    vector<Entity*> entities;
    Neighbour neighbour[4];
    Uint8 flags;
    TileSet* tiles;
    Uint16 music;

    Level();
    ~Level();

    bool load(const char*);
    void save(const char*);

    void render();
};

#endif /* LEVEL_H_ */
