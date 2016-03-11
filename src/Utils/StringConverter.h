/*
 * StringConverter.h
 *
 *  Created on: 25.10.2013
 *      Author: sebastian
 */

#ifndef OTHER_H_
#define OTHER_H_

#include <string>
#include <sstream>

template <class T>
T stringToType(std::string str) {
  std::stringstream converter(str);
  T ret;
  converter >> ret;
  return ret;
}

template <class T>
std::string typeToString(T type) {
  std::stringstream converter;
  converter << type;
  return converter.str();
}

#endif /* OTHER_H_ */
