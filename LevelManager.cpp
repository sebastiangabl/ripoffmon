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

Level* LevelManager::getLevel(unsigned id) {
  if (id_map.find(id) == id_map.end()) {
    Level* l = new Level(id);
    if (!l->load(string("leveldata/" + typeToString(id) + ".dat").c_str())) {
      cerr << "WARNING: Level " << id << " could not be loaded!\n";
    }
    id_map[id] = l;
  }
  return id_map[id];
}

Level* LevelManager::getCurrentLevel() {
  return getLevel(current_level);
}

Level* LevelManager::changeLevel(unsigned id) {
  current_level = id;
  return getCurrentLevel();
}

void LevelManager::free() {
  for (map<unsigned, Level*>::iterator it = id_map.begin(); it != id_map.end(); it++) {
    delete it->second;
  }
  id_map.clear();
}
