#include "bishop.h"
Bishop::Bishop(Player *side) : Piece(side) {}
Bishop::~Bishop() {}

box *Bishop::getDrawingA() { return &bishopA; }
box *Bishop::getDrawingB() { return &bishopB; }
bool Bishop::checkMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == dy)
    return true;

  std::cout << "Illegal Move\n";
  return false;
}

box Bishop::bishopA = {{
    {"█████████"},
    {"███(/)███"},
    {"███▋ ▐███"},
    {"███▖ ▗███"},
    {"██▙▄▄▄▟██"},
}};

box Bishop::bishopB = {{
    {"█████████"},
    {"███(/)███"},
    {"███▋ ▐███"},
    {"███▖ ▗███"},
    {"██▙▄▄▄▟██"},
}};
