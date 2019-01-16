#include "rook.h"
Rook::Rook(Player *side) : Piece(side) {}
Rook::~Rook() {}

box *Rook::getDrawingA() { return &rookA; }
box *Rook::getDrawingB() { return &rookB; }

bool Rook::checkMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == 0 && dy != 0)
    return true;

  if (dx != 0 && dy == 0)
    return true;

  std::cout << "Illegal Move\n";
  return false;
}

box Rook::rookA = {{
    {"░░░░░░░░░"},
    {"░░▅░▅░▅░░"},
    {"░░▝███▘░░"},
    {"░░▅███▅░░"},
    {"░░░░░░░░░"},
}};

box Rook::rookB = {{
    {"█████████"},
    {"██▀█▀█▀██"},
    {"██▙   ▟██"},
    {"██▀   ▀██"},
    {"█████████"},
}};
