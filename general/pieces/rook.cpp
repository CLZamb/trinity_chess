#include "rook.h"
Rook::Rook(Player *side) : Piece(side) {}
Rook::~Rook() {}

box *Rook::getDrawingWSquare() {
  if (pPlayer->getColor() == "black")
    return &rookWhiteBoxP2;
  else
    return &rookWhiteBoxP1;
}
box *Rook::getDrawingBSquare() {
  if (pPlayer->getColor() == "black")
    return &rookBlackBoxP2;
  else
    return &rookBlackBoxP1;
}

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

box Rook::rookWhiteBoxP2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m██▀█▀█▀██\033[0m"},
    {"\033[7m██▙   ▟██\033[0m"},
    {"\033[7m██▀   ▀██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Rook::rookBlackBoxP2 = {{
    {"█████████"},
    {"██▀█▀█▀██"},
    {"██▙   ▟██"},
    {"██▀   ▀██"},
    {"█████████"},
}};

box Rook::rookWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m██▀█▀█▀██\033[0m"},
    {"\033[7m\033[1;37m██▙   ▟██\033[0m"},
    {"\033[7m\033[1;37m██▀   ▀██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Rook::rookBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m██▀█▀█▀██\033[0m"},
    {"\033[1;37m██▙   ▟██\033[0m"},
    {"\033[1;37m██▀   ▀██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
