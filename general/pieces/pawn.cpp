#include "pawn.h"

Pawn::Pawn(Player *side) : Piece(side) {
  if (pPlayer->getColorPieces() == "black") {
    pieceCurrentBlackBox = &PawnBlackBoxP2;
    pieceCurrentWhiteBox = &PawnWhiteBoxP2;
    oneSpaceForward = -1;
  } else {
    pieceCurrentBlackBox = &PawnBlackBoxP1;
    pieceCurrentWhiteBox = &PawnWhiteBoxP1;
    oneSpaceForward = 1;
  }
}

Pawn::~Pawn() {}

bool Pawn::checkMove(Position from, Position to) {
  // row    = y = a...h ->
  // column = x = 0...7 ^
  int dx = abs(from.getPositionX() - to.getPositionX());
  int y = from.getPositionY();
  int y2 = to.getPositionY();
  int nextY = y + oneSpaceForward;

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
    nextY = nextY + oneSpaceForward;
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
