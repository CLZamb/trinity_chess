#include "pawn.h"

Pawn::Pawn(Player *side) : Piece(side) {}

Pawn::~Pawn() {}

box *Pawn::getDrawingWSquare() {
  if (pPlayer->getColor() == "black")
    return &PawnWhiteBoxP2;
  else
    return &PawnWhiteBoxP1;
}

box *Pawn::getDrawingBSquare() {
  if (pPlayer->getColor() == "black")
    return &PawnBlackBoxP2;
  else
    return &PawnBlackBoxP1;
}

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
box Pawn::PawnWhiteBoxP2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m███( )███\033[0m"},
    {"\033[7m███▛ ▜███\033[0m"},
    {"\033[7m██▛   ▜██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Pawn::PawnBlackBoxP2 = {{
    {"█████████"},
    {"███( )███"},
    {"███▛ ▜███"},
    {"██▛   ▜██"},
    {"█████████"},
}};

box Pawn::PawnWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m███( )███\033[0m"},
    {"\033[7m\033[1;37m███▛ ▜███\033[0m"},
    {"\033[7m\033[1;37m██▀   ▀██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Pawn::PawnBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m███( )███\033[0m"},
    {"\033[1;37m███▛ ▜███\033[0m"},
    {"\033[1;37m██▀   ▀██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
