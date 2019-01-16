#include "pawn.h"

Pawn::Pawn(Player *side) : Piece(side) {}

Pawn::~Pawn() {}

box *Pawn::getDrawingA() { return &pawnA; }
box *Pawn::getDrawingB() { return &pawnB; }
bool Pawn::checkMove(Position from, Position to) {

  // row    = y = a...h ->
  // column = x = 0...7 ^
  int dx = abs(from.getPositionX() - to.getPositionX());
  int y = from.getPositionY();
  int y2 = to.getPositionY();
  int nextY = 0;

  if (pPlayer->getColor() == "black") {
    nextY = y + 1;
  } else {
    nextY = y - 1;
  }

  if (isCapturing()) {
    capturing = false;
    std::cout << "is capturing" << std::endl;
    if (nextY == y2 && dx == 1)
      return true;

  } else if (nextY == y2 && dx == 0) {

    return true;
  }

  std::cout << "start y == " << y2 << " next == " << nextY;
  // the diference should be 1 on the y axis and
  std::cout << "Pawn Illegal Move\n";
  return false;
}
box Pawn::pawnA = {{
    {"░░░░░░░░░"},
    {"░░░⬤ ░░░░"},
    {"░░░▟▙░░░░"},
    {"░░▀▀▀▀░░░"},
    {"░░░░░░░░░"},
}};

box Pawn::pawnB = {{
    {"█████████"},
    {"███⬤ ████"},
    {"███▘▝████"},
    {"██▄▄▄▄███"},
    {"█████████"},
}};
