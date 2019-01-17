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
    if (nextY == y2 && dx == 1)
      return true;

  } else if (nextY == y2 && dx == 0) {
    if (firstMove)
      firstMove = false;
    return true;
  }

  if (firstMove) {
    if (pPlayer->getColor() == "black") {
      nextY++;
    } else {
      nextY--;
    }
    if (nextY == y2 && dx == 0) {
      firstMove = false;
      return true;
    }
  }

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
