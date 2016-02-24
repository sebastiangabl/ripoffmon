/*
 * LevelManager.cpp
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#include "LevelManager.h"
#include "utils/StringConverter.h"
#include <iostream>
#include <thread>

using namespace std;

map<unsigned, Level*> LevelManager::id_map;
unsigned LevelManager::current_level = 1;

Level* LevelManager::getLevel(unsigned id, bool load_neighbours) {
  if (!id) {
    return 0;
  }
  if (id_map.find(id) == id_map.end()) {
    Level* l = new Level(id);
    if (!l->load(string("leveldata/" + typeToString(id) + ".dat").c_str())) {
      cerr << "[Thread" << this_thread::get_id() << "] ERROR: Level " << id << " could not be loaded!\n";
    } else {
      cout << "[Thread" << this_thread::get_id() << "] INFO: Level " << id << " loaded.\n";
    }
    id_map[id] = l;
  }
  if (load_neighbours) {
    thread(&LevelManager::getLevel, id_map[id]->neighbour[Level::Neighbour::RIGHT].id, false).detach();
    thread(&LevelManager::getLevel, id_map[id]->neighbour[Level::Neighbour::TOP].id, false).detach();
    thread(&LevelManager::getLevel, id_map[id]->neighbour[Level::Neighbour::LEFT].id, false).detach();
    thread(&LevelManager::getLevel, id_map[id]->neighbour[Level::Neighbour::BOTTOM].id, false).detach();
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
