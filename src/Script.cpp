/*
 * Script.cpp
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#include "Script.h"

#include "Managers/Flags.h"

using namespace std;

Script::Script(Uint16 id, short xx, short yy, Uint8 flr, Uint16 flg, bool interact) {
  x = xx;
  y = yy;
  on_floor = flr;
  flag = flg;
  interact_activation = interact;
  activated = false;
  script = LuaScriptManager::getLuaScript(id);
}

Script::~Script() {
}

void Script::setArguments(vector<LuaArg> args) {
  arguments = args;
}

bool Script::checkActivation(Entity* e) {
  if (!script || Flags::get(flag)) {
    return false;
  }
  if (!interact_activation) {
    if (e->x == x && e->y == y && e->prev_x == x && e->prev_y == y && !activated) {
      activated = true;
      script->setVariable("caller", unsigned(e));
      script->execute(arguments);
      return true;
    } else if (!(e->x == x && e->y == y && e->prev_x == x && e->prev_y == y)) {
      activated = false;
      return false;
    }
  }
  return false;
}
