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
#include <map>
#include "Entity.h"
#include "LevelData.h"
#include "defines.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>

using std::string;
using std::vector;
using std::map;
using sf::RenderTexture;
using sf::Texture;

class Level {
  public:
    static Texture debug_texture;

    class Neighbour {
      public:
        enum Direction {
          RIGHT = 0, TOP, LEFT, BOTTOM
        };
        unsigned short id;
        short offset;
        Neighbour(unsigned short i = 0, short off = 0) : id(i), offset(off) {}
    };

    RenderTexture texture_back, texture_front;
    bool loaded;
    unsigned short id;
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
