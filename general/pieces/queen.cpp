#include "queen.h"
Queen::Queen(Player *side) : Piece(side) {
  if (pPlayer->getColorPieces() == "black") {
    pieceCurrentBlackBox = &queenBlackBoxP2;
    pieceCurrentWhiteBox = &queenWhiteBoxP2;
  } else {
    pieceCurrentBlackBox = &queenBlackBoxP1;
    pieceCurrentWhiteBox = &queenWhiteBoxP1;
  }
}

Queen::~Queen() {}

bool Queen::checkMove(Position from, Position to) {
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

box Queen::queenWhiteBoxP2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m██ █ █ ██\033[0m"},
    {"\033[7m██     ██\033[0m"},
    {"\033[7m██     ██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Queen::queenBlackBoxP2 = {{
    {"█████████"},
    {"██ █ █ ██"},
    {"██     ██"},
    {"██     ██"},
    {"█████████"},
}};

box Queen::queenWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m██ █ █ ██\033[0m"},
    {"\033[7m\033[1;37m██     ██\033[0m"},
    {"\033[7m\033[1;37m██     ██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Queen::queenBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m██ █ █ ██\033[0m"},
    {"\033[1;37m██     ██\033[0m"},
    {"\033[1;37m██     ██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
