/*
 * LevelManager.cpp
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#include "LevelManager.h"

#include <iostream>
#include <string>
#include <utility>

#include "utils/StringConverter.h"

using namespace std;

map<Uint16, Level*> LevelManager::id_map;
unsigned LevelManager::current_level = 1;

Level* LevelManager::getLevel(Uint16 id, bool async) {
  if (!id) {
    return 0;
  }
  if (id_map.find(id) == id_map.end()) {
    id_map[id] = new Level();
    if (!id_map[id]->load(string("leveldata/" + typeToString(id) + ".dat").c_str())) {
      cerr << "Failed to load level \"" << string("leveldata/" + typeToString(id) + ".dat") << "\"!\n";
    }
  }
  return id_map[id];
}

Level* LevelManager::getCurrentLevel() {
  return getLevel(current_level);
}

Level* LevelManager::changeLevel(Uint16 id) {
  current_level = id;
  return getLevel(current_level);
}

void LevelManager::free() {
  for (map<Uint16, Level*>::iterator it = id_map.begin(); it != id_map.end(); it++) {
    delete it->second;
  }
  id_map.clear();
}
