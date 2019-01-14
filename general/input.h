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
  std::string playerInput, fromPos, toPos;
  vector<std::string> scan(std::string, std::regex);
  bool validInput = false;

public:
  Input();
  virtual ~Input();
  void getPlayerNextMove(std::string);
  bool equals(std::string);
  Position getPosFrom();
  Position getPosTo();
  bool isValidInput();
  friend ostream &operator<<(ostream &outputStream, const Input &p);
};

#endif /* INPUT_H */
