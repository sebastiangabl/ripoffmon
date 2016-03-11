/*
 * Flags.cpp
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#include "Flags.h"

map<unsigned, bool> Flags::id_map;

bool Flags::get(unsigned short id) {
  if (!id) {
    return false;
  }
  if (id_map.find(id) == id_map.end()) {
    return false;
  }
  return id_map[id];
}

void Flags::set(unsigned short id) {
  id_map[id] = true;
}
