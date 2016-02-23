/*
 * LevelData.h
 *
 *  Created on: 23. Feb. 2016
 *      Author: Sebastian
 */

#ifndef LEVELDATA_H_
#define LEVELDATA_H_

#include "defines.h"

class LevelData {
  public:
    enum Movement {
      BLOCKED = 0, FLOOR, SURF, WATERFALL
    };
    enum Floor {
      SEPERATE = 1, FLOOR1 = 2, FLOOR2 = 4, FLOOR3 = 8, FLOOR4 = 16
    };
    unsigned short width, height;
    byte** movement;
    byte** floors;
    byte** tiles;
    byte** flags;
    LevelData(unsigned short, unsigned short);
    ~LevelData();
};

#endif /* LEVELDATA_H_ */
