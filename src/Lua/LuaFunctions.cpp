/*
 * LuaFunctions.cpp
 *
 *  Created on: 12. März 2016
 *      Author: Sebastian
 */

#include "LuaFunctions.h"

#include <iostream>

using namespace std;

vector<string> LuaFunctions::extractArguments(const char* data) {
  vector<string> r;
  unsigned pos = 0;
  string datastr = string(data);
  while (pos < datastr.length()) {
    unsigned sl = datastr[pos];
    r.push_back(string(datastr, pos + 1, sl));
    pos += 1 + sl;
  }
  return r;
}

double LuaFunctions::test(const char* data) {
  cout << "C++ test function called with arguments: (";
  vector<string> arguments = extractArguments(data);
  for (unsigned i = 0; i < arguments.size(); i++) {
    cout << arguments[i];
    if (i < arguments.size() - 1) {
      cout << ", ";
    }
  }
  cout << ")" << endl;
  return 1337;
}
