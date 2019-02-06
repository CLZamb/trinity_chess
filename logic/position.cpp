#include "position.h"
#include <iostream>

Position::~Position() {}

Position::Position(std::string pos) {
  m_positionX = tolower(pos[0]) - 'a';
  m_positionY = tolower(pos[1]) - '1';
}

void Position::setPosition(const Position pos) {
  m_positionX = pos.m_positionX;
  m_positionY = pos.m_positionY;
}

void Position::setPosition(int x, int y) {
  m_positionX = x;
  m_positionY = y;
}

void Position::setPosition(char x, char y) {
  m_positionX = tolower(x) - 'a';
  m_positionY = tolower(y) - '1';
}

void Position::setPositionX(int x) { this->m_positionX = x; }
void Position::setPositionY(int y) { this->m_positionY = y; }

void Position::operator=(const Position pos) {
  m_positionX = pos.m_positionX;
  m_positionY = pos.m_positionY;
}

char Position::getCharPositionX() { return m_positionX + '1'; }
char Position::getCharPositionY() { return m_positionY + 'a'; }
