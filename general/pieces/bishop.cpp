#include "bishop.h"
Bishop::Bishop(Player *side) : Piece(side) {}
Bishop::~Bishop() {}

box *Bishop::getDrawingWSquare() {
  if (pPlayer->getColor() == "black")
    return &bishopWhiteBoxP2;
  else
    return &bishopWhiteBoxP1;
}
box *Bishop::getDrawingBSquare() {
  if (pPlayer->getColor() == "black")
    return &bishopBlackBoxP2;
  else
    return &bishopBlackBoxP1;
}
bool Bishop::checkMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == dy)
    return true;

  std::cout << "Illegal Move\n";
  return false;
}

box Bishop::bishopWhiteBoxP2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m███(/)███\033[0m"},
    {"\033[7m███▙ ▟███\033[0m"},
    {"\033[7m███▀ ▀███\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Bishop::bishopBlackBoxP2 = {{
    {"█████████"},
    {"███(/)███"},
    {"███▙ ▟███"},
    {"███▀ ▀███"},
    {"█████████"},
}};

box Bishop::bishopWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m███(/)███\033[0m"},
    {"\033[7m\033[1;37m███▙ ▟███\033[0m"},
    {"\033[7m\033[1;37m███▀ ▀███\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Bishop::bishopBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m███(/)███\033[0m"},
    {"\033[1;37m███▙ ▟███\033[0m"},
    {"\033[1;37m███▀ ▀███\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
