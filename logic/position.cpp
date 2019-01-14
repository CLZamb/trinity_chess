#include "position.h"
#include <iostream>

Position::~Position() {}

void Position::setPosition(const Position pos) {
  m_positionX = pos.m_positionX;
  m_positionY = pos.m_positionY;
}

void Position::setPosition(int x, int y) {
  m_positionX = x;
  m_positionY = y;
}

void Position::setPositionX(int x) { this->m_positionX = x; }
void Position::setPositionY(int y) { this->m_positionY = y; }

void Position::operator=(const Position pos) {
  m_positionX = pos.m_positionX;
  m_positionY = pos.m_positionY;
}
