#include "king.h"
King::King(Player *side) : Piece(side) {}

King::~King() {}

box *King::getDrawingA() { return &kingA; }
box *King::getDrawingB() { return &kingB; }

bool King::checkMove(Position from, Position to) {
  int dx = abs(to.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - from.getPositionY());

  if (dx == 1 || dy == 1)
    if (dx < 2 && dy < 2)
      return true;

  std::cout << "Illegal Move\n";
  return false;
}

box King::kingA = {{
    {"         "},
    {"  █ ✚ █  "},
    {"  █████  "},
    {"  █████  "},
    {"         "},
}};

box King::kingB = {{
    {"█████████"},
    {"██ █✜█ ██"},
    {"██     ██"},
    {"██     ██"},
    {"█████████"},
}};
