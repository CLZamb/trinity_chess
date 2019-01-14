#include "queen.h"
Queen::Queen(Player *side) : Piece(side) {}
Queen::~Queen() {}

box *Queen::getDrawingA() { return &queenA; }
box *Queen::getDrawingB() { return &queenB; }

bool Queen::isValidMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == 0 && dy != 0)
    return true;
  else if (dx != 0 && dy == 0)
    return true;
  else if (dx == dy)
    return true;

  std::cout << "Illegal Move\n";
  return false;
}

box Queen::queenA = {{
    {"░░░░░░░░░"},
    {"░░█░█░█░░"},
    {"░░█████░░"},
    {"░░█████░░"},
    {"░░░░░░░░░"},
}};

box Queen::queenB = {{
    {"█████████"},
    {"██ █ █ ██"},
    {"██     ██"},
    {"██     ██"},
    {"█████████"},
}};
