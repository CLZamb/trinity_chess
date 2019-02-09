#include "bishop.h"
Bishop::Bishop(std::string pieceColor) : Piece(pieceColor) {
  if (pieceColor == "black") {
    value = 30;
    pieceCurrentBlackBox = &bishopBlackBoxP2;
    pieceCurrentWhiteBox = &bishopWhiteBoxP2;
  } else {
    value = -30;
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

void Bishop::possibleMoves(std::vector<std::string> &allMoves) {
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
