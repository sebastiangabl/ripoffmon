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
  is_valid = false;
}

LuaArg::LuaArg(string arg) {
  s = arg;
  n = 0;
  is_string = true;
  is_valid = true;
}

LuaArg::LuaArg(double arg) {
  s = "";
  n = arg;
  is_string = false;
  is_valid = true;
}

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

int LuaScript::execute(LuaArg a1, LuaArg a2, LuaArg a3, LuaArg a4, LuaArg a5, LuaArg a6) {
  LuaArg args[] = {a1, a2, a3, a4, a5, a6};

  unsigned i = 0;
  lua_newtable(L);
  while (true) {
    if (args[i].is_valid) {
      lua_pushnumber(L, 1 + i);
      if (args[i].is_string) {
        lua_pushstring(L, args[i].s.c_str());
      } else {
        lua_pushnumber(L, args[i].n);
      }
      lua_rawset(L, -3);
      i++;
    } else {
      break;
    }
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
