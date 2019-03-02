#include "king.h"
King::King(std::string pieceColor, U64 bb)
  : Piece(pieceColor, bb) {
  if (pieceColor == "black") {
    m_piece_type = bK;
    value = 2000;
    pieceCurrentBlackBox = &kingBlackBoxP2;
    pieceCurrentWhiteBox = &kingWhiteBoxP2;
  } else {
    m_piece_type = wK;
    value = -2000;
    pieceCurrentBlackBox = &kingBlackBoxP1;
    pieceCurrentWhiteBox = &kingWhiteBoxP1;
  }
}

King::~King() {}

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
