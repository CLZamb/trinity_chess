#include "knight.h"
Knight::Knight(Player *side) : Piece(side) { knight = true; }

Knight::~Knight() {}

box *Knight::getDrawingWSquare() {
  if (pPlayer->getColor() == "black")
    return &knightWhiteBoxP2;
  else
    return &knightWhiteBoxP1;
}
box *Knight::getDrawingBSquare() {
  if (pPlayer->getColor() == "black")
    return &knightBlackBoxP2;
  else
    return &knightBlackBoxP1;
}

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
    {"\033[7m██     ██\033[0m"},
    {"\033[7m████   ██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Knight::knightBlackBoxP2 = {{
    {"█████████"},
    {"████ █ ██"},
    {"██     ██"},
    {"████   ██"},
    {"█████████"},
}};

box Knight::knightWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m████ █ ██\033[0m"},
    {"\033[7m\033[1;37m██     ██\033[0m"},
    {"\033[7m\033[1;37m████   ██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Knight::knightBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m████ █ ██\033[0m"},
    {"\033[1;37m██     ██\033[0m"},
    {"\033[1;37m████   ██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
