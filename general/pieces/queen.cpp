#include "queen.h"
Queen::Queen(Player *side) : Piece(side) {}
Queen::~Queen() {}

box *Queen::getDrawingWSquare() {
  if (pPlayer->getColor() == "black")
    return &queenWhiteBoxP2;
  else
    return &queenWhiteBoxP1;
}
box *Queen::getDrawingBSquare() {
  if (pPlayer->getColor() == "black")
    return &queenBlackBoxP2;
  else
    return &queenBlackBoxP1;
}

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
