#include "bishop.h"
Bishop::Bishop(Player *side) : Piece(side) {
  if (pPlayer->getColorPieces() == "black") {
    pieceCurrentBlackBox = &bishopBlackBoxP2;
    pieceCurrentWhiteBox = &bishopWhiteBoxP2;
  } else {
    pieceCurrentBlackBox = &bishopBlackBoxP1;
    pieceCurrentWhiteBox = &bishopWhiteBoxP1;
  }
}

Bishop::~Bishop() {}

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
