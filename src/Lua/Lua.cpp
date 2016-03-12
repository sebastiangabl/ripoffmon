/*
 * Lua.cpp
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#include "Lua.h"

#include <iostream>

using namespace std;

FunctionMap LuaScript::function_map;

int LuaScript::externCall(lua_State* L) {
  string function(luaL_checkstring(L, 1));
  FunctionMap::iterator f = function_map.find(function);
  if (f == function_map.end()) {
    cerr << "Function \"" << function << "\" was not found!\n";
    lua_pushnumber(L, -1);
    return 1;
  } else {
    unsigned args = luaL_checknumber(L, 2);
    string data;
    for (unsigned i = 0; i < args; i++) {
      string arg = luaL_checkstring(L, 3 + i);
      data += char(arg.size()) + arg;
    }
    lua_pushnumber(L, f->second(data.c_str()));
    return 1;
  }
}

void LuaScript::setFunctionMap(FunctionMap map) {
  function_map = map;
}

LuaScript::LuaScript(const char* fname) {
  L = luaL_newstate();
  luaL_openlibs(L);
  err = 0;
  int r = luaL_loadfile(L, fname);
  if (!r) {
    r = lua_pcall(L, 0, 0, 0);
  }
  if (r) {
    err = r;
  } else {
    lua_pushcfunction(L, LuaScript::externCall);
    lua_setglobal(L, "externCall");
  }
}

LuaScript::~LuaScript() {
  if (L) {
    lua_close(L);
  }
}

int LuaScript::callFunction(const char* fn, unsigned argc, const char* argv[]) {
  lua_getglobal(L, fn);
  for (unsigned i = 0; i < argc; i++) {
    lua_pushstring(L, argv[i]);
  }
  lua_pcall(L, argc, 0, 0);
  return 1;
}

string LuaScript::getLastError() {
  if (err) {
    string errstr(lua_tostring(L, -1));
    lua_pop(L, 1);
    err = 0;
    return errstr;
  }
  return string();
}

void LuaScript::setVariable(const char* vn, float val) {
  lua_pushnumber(L, val);
  lua_setglobal(L, vn);
}

void LuaScript::setVariable(const char* vn, string val) {
  lua_pushstring(L, val.c_str());
  lua_setglobal(L, vn);
}
