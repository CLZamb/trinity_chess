#include "pawn.h"

Pawn::Pawn(std::string pieceColor, Position initalPos)
    : Piece(pieceColor), initial(initalPos) {
  if (pieceColor == "black") {
    value = 10;
    pieceCurrentBlackBox = &PawnBlackBoxP2;
    pieceCurrentWhiteBox = &PawnWhiteBoxP2;
    oneSpaceForward = DOWN;
  } else {
    value = -10;
    pieceCurrentBlackBox = &PawnBlackBoxP1;
    pieceCurrentWhiteBox = &PawnWhiteBoxP1;
    oneSpaceForward = UP;
  }
}

Pawn::~Pawn() {}

bool Pawn::isFirstMove() {
  return ((initial.getPositionY() == pos.getPositionX()) &&
          (initial.getPositionX() == pos.getPositionY()));
}

bool Pawn::checkMove(Position from, Position to) {
  // row    = y = a...h ->
  // column = x = 0...7 ^
  int dx = abs(from.getPositionX() - to.getPositionX());
  int y = from.getPositionY();
  int y2 = to.getPositionY();
  int nextY = y + oneSpaceForward;

  if (isCapturing()) {
    capturing = false;
    if (nextY == y2 && dx == 1)
      return true;

  } else if (nextY == y2 && dx == 0) {
    return true;
  } else if (isFirstMove()) {
    nextY = nextY + oneSpaceForward;
    if (nextY == y2 && dx == 0)
      return true;
  }

  // the diference should be 1 on the y axis and
  // std::cout << "Pawn Illegal Move\n";
  return false;
}

void Pawn::possibleMoves(std::vector<std::string> &allMoves) {
  int X[3] = {0, LEFT, RIGHT};
  int Y[3] = {oneSpaceForward, oneSpaceForward, oneSpaceForward};

  std::string movestr;
  std::string currentpos;

  currentpos = pos.getCharPositionY();
  currentpos += pos.getCharPositionX();

  for (int i = 0; i < 3; i++) {
    movestr = currentpos;
    movestr += pos.getCharPositionY() + X[i];
    movestr += pos.getCharPositionX() + Y[i];
    allMoves.push_back(movestr);
  }

  if (isFirstMove()) {
    movestr = currentpos;
    movestr += pos.getCharPositionY();
    movestr += pos.getCharPositionX() + oneSpaceForward + oneSpaceForward;
    allMoves.push_back(movestr);
  }
}

box Pawn::PawnWhiteBoxP2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m███( )███\033[0m"},
    {"\033[7m███▛ ▜███\033[0m"},
    {"\033[7m██▛   ▜██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Pawn::PawnBlackBoxP2 = {{
    {"█████████"},
    {"███( )███"},
    {"███▛ ▜███"},
    {"██▛   ▜██"},
    {"█████████"},
}};

box Pawn::PawnWhiteBoxP1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m███( )███\033[0m"},
    {"\033[7m\033[1;37m███▛ ▜███\033[0m"},
    {"\033[7m\033[1;37m██▀   ▀██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Pawn::PawnBlackBoxP1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m███( )███\033[0m"},
    {"\033[1;37m███▛ ▜███\033[0m"},
    {"\033[1;37m██▀   ▀██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
