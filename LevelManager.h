/*
 * LevelManager.h
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

#include <map>
#include "Level.h"
#include <SFML/Config.hpp>

using std::map;
using sf::Uint16;

class LevelManager {
  private:
    static map<Uint16, Level*> id_map;
    static unsigned current_level;
    static void loadLevel(Level*);
  public:
    static Level* getLevel(Uint16, bool = false);
    static Level* getCurrentLevel();
    static Level* changeLevel(Uint16);

    static void free();
};

#endif /* LEVELMANAGER_H_ */
