#include "knight.h"
Knight::Knight(Player *side) : Piece(side) {}

Knight::~Knight() {}

box *Knight::getDrawingA() { return &knightA; }
box *Knight::getDrawingB() { return &knightB; }

bool Knight::isValidMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());
  if (dx == 2 && dy == 1)
    return true;

  else if (dx == 1 && dy == 2)
    return true;

  std::cout << "Illegal Move\n";
  return false;
}
// ████▀▛▜███
// ██▀    ▜██
// ██▆▇   ▜██
// ██▀    ▀██
// ██████████
//
box Knight::knightA = {{
    {"███▀▛▜███"},
    {"██▀   ▜██"},
    {"██▆▇   ▜█"},
    {"██▀    ▀█"},
    {"█████████"},
}};

box Knight::knightB = {{
    {"███▀▛▜███"},
    {"██▀   ▜██"},
    {"██▆▇   ▜█"},
    {"██▀    ▀█"},
    {"█████████"},
}};
