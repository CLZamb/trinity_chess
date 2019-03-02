#include "knight.h"
Knight::Knight(std::string pieceColor, U64 bb) : Piece(pieceColor, bb) {
  if (pieceColor == "black") {
    m_piece_type = bN;
    value = 30;
    pieceCurrentBlackBox = &knightBlackBoxP2;
    pieceCurrentWhiteBox = &knightWhiteBoxP2;
  } else {
    m_piece_type = wN;
    value = -30;
    pieceCurrentBlackBox = &knightBlackBoxP1;
    pieceCurrentWhiteBox = &knightWhiteBoxP1;
  }
}

Knight::~Knight() {}

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
