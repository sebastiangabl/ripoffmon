/*
 * LevelManager.h
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

#include <SFML/Config.hpp>
#include <map>

#include "../Level.h"

using std::map;
using sf::Uint16;

class LevelManager {
  private:
    static map<Uint16, Level*> id_map;
    static unsigned current_level;
  public:
    static Level* getLevel(Uint16, bool = false);
    static Level* getCurrentLevel();
    static Level* changeLevel(Uint16);

    static void free();
};

#endif /* LEVELMANAGER_H_ */
