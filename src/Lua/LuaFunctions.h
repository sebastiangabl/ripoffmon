/*
 * LuaFunctions.h
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#ifndef SRC_LUA_LUAFUNCTIONS_H_
#define SRC_LUA_LUAFUNCTIONS_H_

#include <string>
#include <vector>

#include "Lua.h"

class LuaFunctions {
  private:
    static vector<string> extractArguments(const char*);
  public:
    static double test(const char*);
};

#endif /* SRC_LUA_LUAFUNCTIONS_H_ */
