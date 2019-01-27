#include "knight.h"
Knight::Knight(Player *side) : Piece(side) {
  if (pPlayer->getColorPieces() == "black") {
    pieceCurrentBlackBox = &knightBlackBoxP2;
    pieceCurrentWhiteBox = &knightWhiteBoxP2;
  } else {
    pieceCurrentBlackBox = &knightBlackBoxP1;
    pieceCurrentWhiteBox = &knightWhiteBoxP1;
  }
}

Knight::~Knight() {}

bool Knight::checkMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == 2 && dy == 1)
    return true;

  else if (dx == 1 && dy == 2)
    return true;

  std::cout << "Illegal Move\n";
  return false;
}

box Knight::knightWhiteBoxP2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m████ █ ██\033[0m"},
    {"\033[7m███    ██\033[0m"},
    {"\033[7m████   ██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Knight::knightBlackBoxP2 = {{
    {"█████████"},
    {"████ █ ██"},
    {"███    ██"},
    {"████   ██"},
    {"█████████"},
}};

box Knight::knightWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m████ █ ██\033[0m"},
    {"\033[7m\033[1;37m███    ██\033[0m"},
    {"\033[7m\033[1;37m████   ██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Knight::knightBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m████ █ ██\033[0m"},
    {"\033[1;37m███    ██\033[0m"},
    {"\033[1;37m████   ██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
