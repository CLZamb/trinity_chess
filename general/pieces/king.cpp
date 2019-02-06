#include "king.h"
King::King(std::string pieceColor) : Piece(pieceColor) {
  if (pieceColor == "black") {
    value = -900;
    pieceCurrentBlackBox = &kingBlackBoxP2;
    pieceCurrentWhiteBox = &kingWhiteBoxP2;
  } else {
    value = 900;
    pieceCurrentBlackBox = &kingBlackBoxP1;
    pieceCurrentWhiteBox = &kingWhiteBoxP1;
  }
}

King::~King() {}

bool King::checkMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == 1 || dy == 1)
    if (dx < 2 && dy < 2)
      return true;

  std::cout << "Illegal Move\n";
  return false;
}

void King::possibleMoves(std::vector<std::string> &allMoves) {
  int X[8] = {0, 0, -1, 1, -1, 1, -1, 1};
  int Y[8] = {1, -1, 0, 0, 1, 1, -1, -1};

  currentpos = pos.getCharPositionY();
  currentpos += pos.getCharPositionX();

  for (int i = 0; i < 8; i++) {
    movestr = currentpos;
    movestr += pos.getCharPositionY() + X[i];
    movestr += pos.getCharPositionX() + Y[i];
    allMoves.push_back(movestr);
  }
}

box King::kingWhiteBoxP2 = {{
    {"░░▁ ✜ ▁░░"},
    {"░( ╲|╱ )░"},
    {"░░╲▁▁▁╱░░"},
    {"░[▁▁▁▁▁]░"},
    {"░░░░░░░░░"},
}};

box King::kingBlackBoxP2 = {{
    {"██\033[0;32m▁ ✜ ▁\033[0m██"},
    {"█\033[0;32m( ╲|╱ )\033[0m█"},
    {"██\033[0;32m╲▁▁▁╱\033[0m██"},
    {"█\033[0;32m[▁▁▁▁▁]\033[0m█"},
    {"█████████"},
}};

box King::kingWhiteBoxP1 = {{
    {"\033[1;37m░░▁ ✜ ▁░░\033[0m"},
    {"\033[1;37m░( ╲|╱ )░\033[0m"},
    {"\033[1;37m░░╲▁▁▁╱░░\033[0m"},
    {"\033[1;37m░[▁▁▁▁▁]░\033[0m"},
    {"\033[1;37m░░░░░░░░░\033[0m"},
}};

box King::kingBlackBoxP1 = {{
    {"\033[1;37m██▁ ✜ ▁██\033[0m"},
    {"\033[1;37m█( ╲|/ )█\033[0m"},
    {"\033[1;37m██╲▁▁▁╱██\033[0m"},
    {"\033[1;37m█[▁▁▁▁▁]█\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
