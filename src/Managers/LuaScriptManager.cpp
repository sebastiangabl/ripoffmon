/*
 * LuaScriptManager.cpp
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#include "LuaScriptManager.h"

#include "../Utils/StringConverter.h"

using namespace std;

map<Uint16, LuaScript*> LuaScriptManager::id_map;

LuaScript* LuaScriptManager::getLuaScript(Uint16 id) {
  if (!id) {
    return 0;
  }
  if (id_map.find(id) == id_map.end()) {
    id_map[id] = new LuaScript(string("scripts/" + typeToString(id) + ".lua").c_str());
  }
  return id_map[id];
}

void LuaScriptManager::free() {
  for (map<Uint16, LuaScript*>::iterator it = id_map.begin(); it != id_map.end(); it++) {
    delete it->second;
  }
  id_map.clear();
}
