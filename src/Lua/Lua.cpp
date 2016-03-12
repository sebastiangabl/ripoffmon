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

LuaArg::LuaArg() {
  s = "";
  n = 0;
  is_string = false;
}

LuaArg::LuaArg(string arg) {
  s = arg;
  n = 0;
  is_string = true;
}

LuaArg::LuaArg(double arg) {
  s = "";
  n = arg;
  is_string = false;
}

int LuaScript::externCall(lua_State* L) {
  string function(luaL_checkstring(L, 1));
  FunctionMap::iterator f = function_map.find(function);
  if (f == function_map.end()) {
    cerr << "Function \"" << function << "\" was not found!\n";
    lua_pushnumber(L, -1);
    return 1;
  } else {
    unsigned argc = luaL_checknumber(L, 2);
    vector<string> args;
    for (unsigned i = 0; i < argc; i++) {
      args.push_back(luaL_checkstring(L, 3 + i));
    }
    lua_pushnumber(L, f->second(args));
    return 1;
  }
}

void LuaScript::setFunctionMap(FunctionMap map) {
  function_map = map;
}

LuaScript::LuaScript(string fname) {
  L = luaL_newstate();
  luaL_openlibs(L);
  file_name = fname;
  lua_pushcfunction(L, LuaScript::externCall);
  lua_setglobal(L, "externCall");
}

LuaScript::~LuaScript() {
  if (L) {
    lua_close(L);
  }
}

int LuaScript::execute(vector<LuaArg> args) {
  lua_newtable(L);
  for (unsigned i = 0; i < args.size(); i++) {
    lua_pushnumber(L, 1 + i);
    if (args[i].is_string) {
      lua_pushstring(L, args[i].s.c_str());
    } else {
      lua_pushnumber(L, args[i].n);
    }
    lua_rawset(L, -3);
  }
  lua_setglobal(L, "arg");

  int r = luaL_loadfile(L, file_name.c_str());
  if (!r) {
    r = lua_pcall(L, 0, 0, 0);
  }
  if (r) {
    string errstr(lua_tostring(L, -1));
    lua_pop(L, 1);
    cerr << errstr << endl;
    cerr.flush();
  }
  return !r;
}

void LuaScript::setVariable(const char* vn, double val) {
  lua_pushnumber(L, val);
  lua_setglobal(L, vn);
}

void LuaScript::setVariable(const char* vn, string val) {
  lua_pushstring(L, val.c_str());
  lua_setglobal(L, vn);
}
