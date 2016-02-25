/*
 * File.cpp
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#include "File.h"

File::File() {
  size = 0;
}

File::~File() {
  close();
}

bool File::open(const char* fname, std::_Ios_Openmode flags) {
  file.open(fname, flags);
  if (isOpen()) {
    file.seekg(0, file.end);
    size = file.tellg();
    file.seekg(0, file.beg);
  }
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
  size += data.size() + 1;
  return (data.size() + 1);
}

string File::read() {
  string data;
  char c;
  while (!eof()) {
    file.read(&c, sizeof(char));
    if (c == '\0') {
      break;
    } else {
      data += c;
    }
  }
  return data;
}

bool File::eof() {
  return (file.tellg() >= size || file.eof());
}
