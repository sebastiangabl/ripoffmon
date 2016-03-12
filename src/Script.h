/*
 * Script.h
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#ifndef SRC_SCRIPT_H_
#define SRC_SCRIPT_H_

#include <SFML/Config.hpp>
#include <vector>

#include "Entity.h"
#include "Managers/LuaScriptManager.h"

using sf::Uint8;
using sf::Uint16;
using std::vector;

class Script {
  public:
    short x, y;
    Uint8 on_floor;
    Uint16 flag;
    bool interact_activation;
    bool activated;
    LuaScript* script;
    vector<LuaArg> arguments;

    Script(Uint16 = 0, short = 0, short = 0, Uint8 = 0, Uint16 = 0, bool = false);
    ~Script();

    void setArguments(vector<LuaArg>);

    bool checkActivation(Entity*);
};

#endif /* SRC_SCRIPT_H_ */
