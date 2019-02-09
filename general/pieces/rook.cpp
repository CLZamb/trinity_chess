#include "rook.h"
Rook::Rook(std::string pieceColor) : Piece(pieceColor) {
  if (pieceColor == "black") {
    value = 50;
    pieceCurrentBlackBox = &rookBlackBoxP2;
    pieceCurrentWhiteBox = &rookWhiteBoxP2;
  } else {
    value = -50;
    pieceCurrentBlackBox = &rookBlackBoxP1;
    pieceCurrentWhiteBox = &rookWhiteBoxP1;
  }
}

Rook::~Rook() {}

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

void Rook::possibleMoves(std::vector<std::string> &allMoves) {
  currentpos = pos.getCharPositionY();
  currentpos += pos.getCharPositionX();

  y = pos.getCharPositionY();
  x = pos.getCharPositionX();

  // all possible moves in the up
  for (i = x + 1; i <= '8'; i++) {
    movestr = currentpos;
    movestr += pos.getCharPositionY();
    movestr += i;
    allMoves.push_back(movestr);
  }
  // all possible moves in the down
  for (i = x - 1; i >= '1'; i--) {
    movestr = currentpos;
    movestr += pos.getCharPositionY();
    movestr += i;
    allMoves.push_back(movestr);
  }

  // all possible moves to the right
  for (i = y + 1; i <= 'h'; i++) {
    movestr = currentpos;
    movestr += i;
    movestr += pos.getCharPositionX();
    allMoves.push_back(movestr);
  }

  // all possible moves to the left
  for (i = y - 1; i >= 'a'; i--) {
    movestr = currentpos;
    movestr += i;
    movestr += pos.getCharPositionX();
    allMoves.push_back(movestr);
  }
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
