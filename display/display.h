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
  // protected:
  // int *arrays = new int[10];
  // void setUpGame();
  // void initializeAllMessages();

public:
  virtual void print() = 0;
  // Display();
  virtual ~Display() = 0;

  // void beginGame();
  // void display(std::string message);
  // void fillingBoard(box *, Position pos);
  // void printBoard();
  // box *getBoardDisplay();
  // void setPieceAtPosition(Piece *, int x, int y);
};
#endif /* DISPLAY_H */
