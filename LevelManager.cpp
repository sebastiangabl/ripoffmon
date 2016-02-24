/*
 * LevelManager.cpp
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#include "LevelManager.h"
#include "utils/StringConverter.h"
#include <iostream>

using namespace std;

map<unsigned, Level*> LevelManager::id_map;
unsigned LevelManager::current_level = 1;

void LevelManager::loadLevel(Level* l) {
  if (!l->load(string("leveldata/" + typeToString(l->id) + ".dat").c_str())) {
    cerr << "ERROR: Level " << l->id << " could not be loaded!\n";
  }
}

Level* LevelManager::getLevel(unsigned id, bool async) {
  if (!id) {
    return 0;
  }
  if (id_map.find(id) == id_map.end()) {
    id_map[id] = new Level(id);
    loadLevel(id_map[id]);
  }
  return id_map[id];
}

Level* LevelManager::getCurrentLevel() {
  return getLevel(current_level);
}

Level* LevelManager::changeLevel(unsigned id) {
  current_level = id;
  return getLevel(current_level);
}

void LevelManager::free() {
  for (map<unsigned, Level*>::iterator it = id_map.begin(); it != id_map.end(); it++) {
    delete it->second;
  }
  id_map.clear();
}
