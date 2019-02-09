#include "queen.h"
Queen::Queen(std::string pieceColor) : Piece(pieceColor) {
  if (pieceColor == "black") {
    value = 90;
    pieceCurrentBlackBox = &queenBlackBoxP2;
    pieceCurrentWhiteBox = &queenWhiteBoxP2;
  } else {
    value = -90;
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

void Queen::possibleMoves(std::vector<std::string> &allMoves) {
  currentpos = pos.getCharPositionY();
  currentpos += pos.getCharPositionX();

  y = pos.getCharPositionY();
  x = pos.getCharPositionX();

  // all possible moves in the up-right
  for (i = x + 1, j = y + 1; i <= '8' && j <= 'h'; i++, j++) {
    movestr = currentpos;
    movestr += j;
    movestr += i;
    allMoves.push_back(movestr);
  }
  // all possible moves in the down left
  for (i = x - 1, j = y - 1; i >= '1' && j >= 'a'; i--, j--) {
    movestr = currentpos;
    movestr += j;
    movestr += i;
    allMoves.push_back(movestr);
  }

  // all possible moves to the down right
  for (i = y + 1, j = x - 1; i <= 'h' && j >= '1'; i++, j--) {
    movestr = currentpos;
    movestr += i;
    movestr += j;
    allMoves.push_back(movestr);
  }

  // all possible moves to the up left
  for (i = y - 1, j = x + 1; i >= 'a' && j <= '8'; i--, j++) {
    movestr = currentpos;
    movestr += i;
    movestr += j;
    allMoves.push_back(movestr);
  }

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
