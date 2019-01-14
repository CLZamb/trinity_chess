#include "pawn.h"

Pawn::Pawn(Player *side) : Piece(side) {}

Pawn::~Pawn() {}

box *Pawn::getDrawingA() { return &pawnA; }
box *Pawn::getDrawingB() { return &pawnB; }
bool Pawn::isValidMove(Position from, Position to) {
  // row    = y = a...h ->
  // column = x = 0...7 ^
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dy == 1 && dx == 0)
    return true;
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
