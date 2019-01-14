// File: position.h
#ifndef POSITION_H
#define POSITION_H
#pragma once

#include <iostream>

class Position {
private:
public:
  int m_positionX;
  int m_positionY;
  Position(int x = 0, int y = 0) : m_positionX(x), m_positionY(y) {}
  virtual ~Position();

  void setPosition(int x, int y);
  void setPositionX(int x);
  void setPositionY(int y);
  void setPosition(const Position pos);
  int getPositionX() { return m_positionX; }
  int getPositionY() { return m_positionY; }
  int getPositionColumn() { return m_positionX; }
  int getPositionRow() { return m_positionY; }
  Position getPosition() { return *this; }
  void operator=(const Position pos);
};

#endif /* POSITION_H */
