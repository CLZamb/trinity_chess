// File: display.h
#ifndef DISPLAY_H
#define DISPLAY_H
#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Display {

public:
  virtual void print() = 0;
  virtual ~Display() = 0;
};
#endif /* DISPLAY_H */
