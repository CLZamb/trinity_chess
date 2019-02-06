#include "knight.h"
Knight::Knight(std::string pieceColor) : Piece(pieceColor) {
  if (pieceColor == "black") {
    value = -30;
    pieceCurrentBlackBox = &knightBlackBoxP2;
    pieceCurrentWhiteBox = &knightWhiteBoxP2;
  } else {
    value = 30;
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

void Knight::possibleMoves(std::vector<std::string> &allMoves) {
  int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  std::string movestr;
  std::string currentpos;

  currentpos = pos.getCharPositionY();
  currentpos += pos.getCharPositionX();

  for (int i = 0; i < 8; i++) {
    movestr = currentpos;
    movestr += pos.getCharPositionY() + X[i];
    movestr += pos.getCharPositionX() + Y[i];
    allMoves.push_back(movestr);
  }
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
