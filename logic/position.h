// File: position.h
#ifndef POSITION_H
#define POSITION_H
#pragma once

#include <string>

/*
 * @class take care of the position
 * on the board  such that the board konws
 * every position aviliable and what position can be used
 * and where are all the pieces
 * o*/

struct Position {
  explicit Position(int x = 0, int y = 0) : m_positionX(x), m_positionY(y) {}
  explicit Position(char x, char y)
      : m_positionX(tolower(x) - 'a'), m_positionY(tolower(y) - '1') {}
  explicit Position(std::string pos);
  virtual ~Position();

  void setPosition(int x, int y);
  void setPosition(char x, char y);
  void setPositionX(int x);
  void setPositionY(int y);
  void setPosition(const Position pos);
  int getPositionX() { return m_positionX; }
  int getPositionY() { return m_positionY; }
  int getPositionColumn() { return m_positionX; }
  int getPositionRow() { return m_positionY; }
  char getCharPositionX();
  char getCharPositionY();
  void operator=(const Position pos);

  int m_positionX;
  int m_positionY;
};

#endif /* POSITION_H */
