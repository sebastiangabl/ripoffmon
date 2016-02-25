/*
 * File.h
 *
 *  Created on: 19. Feb. 2016
 *      Author: Sebastian
 */

#ifndef FILE_H_
#define FILE_H_

#include <fstream>
#include <string>

using std::fstream;
using std::string;

class File {
  private:
    fstream file;
    unsigned size;
  public:
    File();
    ~File();
    bool open(const char*, std::_Ios_Openmode);
    bool isOpen();
    void close();

    template <class T>
    unsigned write(T);
    unsigned write(string);

    template <class T>
    T read();
    string read();

    bool eof();
};

template<class T>
inline unsigned File::write(T data) {
  file.write((const char*)&data, sizeof(T));
  size += sizeof(T);
  return sizeof(T);
}

template<class T>
inline T File::read() {
  T data;
  file.read((char*)&data, sizeof(T));
  return data;
}

#endif /* FILE_H_ */
