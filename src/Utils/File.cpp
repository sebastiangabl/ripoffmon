/*
 * File.cpp
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#include "File.h"

using namespace std;

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

map<string, string> File::readVorbisComments(const char* fname) {
  map<string, string> m;
  fstream f;
  f.open(fname, fstream::in | fstream::binary);
  if (!f.is_open()) {
    return m;
  }

  f.seekg(26, f.cur);
  unsigned char segments;
  f.read((char*)&segments, sizeof(char));
  unsigned tlen = 0;
  for (unsigned j = 0; j < (unsigned)segments; j++) {
    unsigned char len;
    f.read((char*)&len, sizeof(char));
    tlen += (unsigned)len;
  }
  f.seekg(tlen + 26, f.cur);
  f.read((char*)&segments, sizeof(char));
  f.seekg(segments + 7, f.cur);
  unsigned vendor_size;
  f.read((char*)&vendor_size, sizeof(unsigned));
  f.seekg(vendor_size, f.cur);
  unsigned user_size;
  f.read((char*)&user_size, sizeof(unsigned));
  for (unsigned i = 0; i < user_size; i++) {
    unsigned len;
    f.read((char*)&len, sizeof(unsigned));
    string str;
    char c;
    for (unsigned j = 0; j < len; j++) {
      f.read(&c, sizeof(char));
      str += c;
    }
    m[str.substr(0, str.find('='))] = str.substr(str.find('=') + 1);
  }
  return m;
}
