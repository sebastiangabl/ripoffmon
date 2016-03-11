/*
 * TileSetManager.cpp
 *
 *  Created on: 11. März 2016
 *      Author: Sebastian
 */

#include "TileSetManager.h"

#include <string>

#include "../Utils/StringConverter.h"

using namespace std;

map<Uint8, TileSet*> TileSetManager::id_map;

TileSet* TileSetManager::getTileSet(Uint8 id, bool async) {
  if (!id) {
    return 0;
  }
  if (id_map.find(id) == id_map.end()) {
    id_map[id] = new TileSet();
    id_map[id]->loadFromFile(string("tilesets/" + typeToString((unsigned)id) + ".png").c_str());
  }
  return id_map[id];
}

void TileSetManager::free() {
  for (map<Uint8, TileSet*>::iterator it = id_map.begin(); it != id_map.end(); it++) {
    delete it->second;
  }
  id_map.clear();
}
