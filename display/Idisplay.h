// File: idisplay.h
#ifndef IDISPLAY_H
#define IDISPLAY_H
#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
#ifdef _WIN32
#define CLEAR "cls"
#else
// Assume Unix system
#define CLEAR "clear"
#endif
class IDisplay {

public:
  virtual void print() = 0;
  virtual ~IDisplay() = 0;
};
#endif /* IDISPLAY_H */
