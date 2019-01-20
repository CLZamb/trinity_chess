#include "king.h"
King::King(Player *side) : Piece(side) { king = true; }

King::~King() {}

box *King::getDrawingWSquare() {
  if (pPlayer->getColor() == "black")
    return &kingWhiteBoxP2;
  else
    return &kingWhiteBoxP1;
}

box *King::getDrawingBSquare() {
  if (pPlayer->getColor() == "black")
    return &kingBlackBoxP2;
  else
    return &kingBlackBoxP1;
}

bool King::checkMove(Position from, Position to) {
  int dx = abs(from.getPositionX() - to.getPositionX());
  int dy = abs(from.getPositionY() - to.getPositionY());

  if (dx == 1 || dy == 1)
    if (dx < 2 && dy < 2)
      return true;

  std::cout << "Illegal Move\n";
  return false;
}

#define SH_FG_GREEN "\033[0;32m"

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
