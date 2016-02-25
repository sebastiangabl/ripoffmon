/*
 * Flags.h
 *
 *  Created on: 24. Feb. 2016
 *      Author: Sebastian
 */

#ifndef FLAGS_H_
#define FLAGS_H_

#include <map>

using std::map;

class Flags {
  private:
    static map<unsigned, bool> id_map;
  public:
    static bool get(unsigned short);
    static void set(unsigned short);
};

#endif /* FLAGS_H_ */
