/*
 * LuaScriptManager.h
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#ifndef SRC_MANAGERS_LUASCRIPTMANAGER_H_
#define SRC_MANAGERS_LUASCRIPTMANAGER_H_

#include <SFML/Config.hpp>
#include <map>

#include "../Lua/Lua.h"

using std::map;
using sf::Uint16;

class LuaScriptManager {
  private:
    static map<Uint16, LuaScript*> id_map;
  public:
    static LuaScript* getLuaScript(Uint16);
    static void free();
};

#endif /* SRC_MANAGERS_LUASCRIPTMANAGER_H_ */
