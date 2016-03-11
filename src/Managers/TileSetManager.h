/*
 * TileSetManager.h
 *
 *  Created on: 11. März 2016
 *      Author: Sebastian
 */

#ifndef MANAGERS_TILESETMANAGER_H_
#define MANAGERS_TILESETMANAGER_H_

#include <SFML/Config.hpp>
#include <map>

#include "../TileSet.h"

using std::map;
using sf::Uint8;

class TileSetManager {
  private:
    static map<Uint8, TileSet*> id_map;
  public:
    static TileSet* getTileSet(Uint8, bool = false);
    static void free();
};

#endif /* MANAGERS_TILESETMANAGER_H_ */
