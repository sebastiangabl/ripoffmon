/*
 * LevelData.h
 *
 *  Created on: 23. Feb. 2016
 *      Author: Sebastian
 */

#ifndef LEVELDATA_H_
#define LEVELDATA_H_

#include <SFML/Config.hpp>

using sf::Uint8;
using sf::Uint16;

class LevelData {
  public:
    enum Movement {
      BLOCKED = 0, FLOOR, SURF, WATERFALL,
      LEDGE_RIGHT, LEDGE_UP, LEDGE_LEFT, LEDGE_DOWN,
      PUSH_RIGHT, PUSH_UP, PUSH_LEFT, PUSH_DOWN, TEMP_BLOCKED = 128
    };
    enum Floor {
      SEPERATE = 1, FLOOR1 = 2, FLOOR2 = 4, FLOOR3 = 8, FLOOR4 = 16
    };
    unsigned short width, height;
    Uint8** movement;
    Uint8** floors;
    Uint16** tiles_back;
    Uint16** tiles_front;
    LevelData(unsigned short, unsigned short);
    ~LevelData();
};

#endif /* LEVELDATA_H_ */
