/*
 * defines.h
 *
 *  Created on: 02. Feb. 2016
 *      Author: Sebastian
 */

#ifndef DEFINES_H_
#define DEFINES_H_

typedef unsigned char byte;

class Neighbour {
  public:
    enum Direction {
      RIGHT = 0, TOP, LEFT, BOTTOM
    };
    unsigned short id;
    short offset;
    Neighbour(unsigned short i = 0, short off = 0) : id(i), offset(off) {}
};

#endif /* DEFINES_H_ */
