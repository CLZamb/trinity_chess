#include "queen.h"
Queen::Queen(std::string pieceColor, U64 bb) : Piece(pieceColor, bb) {
  if (pieceColor == "black") {
    m_piece_type = bQ;
    value = 90;
    pieceCurrentBlackBox = &queenBlackBoxP2;
    pieceCurrentWhiteBox = &queenWhiteBoxP2;
  } else {
    m_piece_type = wQ;
    value = -90;
    pieceCurrentBlackBox = &queenBlackBoxP1;
    pieceCurrentWhiteBox = &queenWhiteBoxP1;
  }
}

Queen::~Queen() {}

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
