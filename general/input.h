// File: input.h
#ifndef INPUT_H
#define INPUT_H

#pragma once
#include "position.h"
#include <iostream>
#include <ostream>
#include <regex>
#include <string>
#include <vector>

using std::ostream;
using std::vector;

class Input {
private:
  std::string playerInput;
  Position fromPos, toPos;
  bool validInput = false;
  vector<std::string> scan(std::string, std::regex);

public:
  Input();
  virtual ~Input();
  void getNextMove(std::string);
  std::string toString();
  Position getPosFrom();
  Position getPosTo();
  bool isValidInput();
};

#endif /* INPUT_H */
