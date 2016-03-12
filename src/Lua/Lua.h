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

typedef map<string, double(*)(vector<string>)> FunctionMap;

class LuaArg {
  public:
    string s;
    double n;
    bool is_string;

    LuaArg();
    LuaArg(string);
    LuaArg(double);
};

class LuaScript {
  private:
    lua_State* L;
    string file_name;
    static FunctionMap function_map;
  public:
    static int externCall(lua_State*);
    static void setFunctionMap(FunctionMap);

    LuaScript(string);
    ~LuaScript();

    int execute(vector<LuaArg> = vector<LuaArg>());

    void setVariable(const char*, double);
    void setVariable(const char*, string);
};

#endif /* SRC_LUA_LUA_H_ */
