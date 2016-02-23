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

using std::map;

class LevelManager {
  private:
    static map<unsigned, Level*> id_map;
    static unsigned current_level;
  public:
    static Level* getLevel(unsigned);
    static Level* getCurrentLevel();
    static Level* changeLevel(unsigned);

    static void free();
};

#endif /* LEVELMANAGER_H_ */
