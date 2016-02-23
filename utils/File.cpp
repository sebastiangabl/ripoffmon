/*
 * File.cpp
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#include "File.h"

File::File() {
}

File::~File() {
  close();
}

bool File::open(const char* fname, std::_Ios_Openmode flags) {
  file.open(fname, flags);
  return isOpen();
}

bool File::isOpen() {
  return file.is_open();
}

void File::close() {
  file.close();
}

unsigned File::write(string data) {
  const char* str = data.c_str();
  file.write(str, data.size() + 1);
  return (data.size() + 1);
}

string File::read() {
  string data;
  char c;
  while (!file.eof()) {
    file.read(&c, sizeof(char));
    if (c == '\0') {
      break;
    } else {
      data += c;
    }
  }
  return data;
}
