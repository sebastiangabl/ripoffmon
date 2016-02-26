/*
 * TileSet.h
 *
 *  Created on: 25. Feb. 2016
 *      Author: Sebastian
 */

#ifndef TILESET_H_
#define TILESET_H_

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Config.hpp>

using std::map;
using sf::Texture;
using sf::Vector2u;
using sf::Uint8;
using sf::Uint16;

class TileSet {
  private:
    map<Uint16, Uint8> flags;
  public:
    enum Flag {
      NONE = 0, ANIMATED = 1, FOREGROUND = 2
    };
    Texture texture;
    unsigned tile_size;
    bool loaded;

    TileSet();
    ~TileSet();
    bool loadFromFile(const char*);
    Vector2u getTileCoords(Uint16);
    Uint8 getTileFlags(Uint16);
};

#endif /* TILESET_H_ */
