/*
 * Lua.h
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#ifndef SRC_LUA_LUA_H_
#define SRC_LUA_LUA_H_

#include <lua.hpp>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::map;
using std::vector;

typedef map<string, double(*)(const char*)> FunctionMap;

class LuaScript {
  private:
    lua_State* L;
    int err;
    static FunctionMap function_map;
  public:
    static int externCall(lua_State*);
    static void setFunctionMap(FunctionMap);

    LuaScript(const char*);
    ~LuaScript();

    int callFunction(const char*, unsigned = 0, const char** = 0);
    string getLastError();

    void setVariable(const char*, float);
    void setVariable(const char*, string);
};

#endif /* SRC_LUA_LUA_H_ */
