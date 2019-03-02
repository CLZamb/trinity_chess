#include "rook.h"
Rook::Rook(std::string pieceColor, U64 bb) : Piece(pieceColor, bb) {
  if (pieceColor == "black") {
    m_piece_type = bR;
    value = 50;
    pieceCurrentBlackBox = &rookBlackBoxP2;
    pieceCurrentWhiteBox = &rookWhiteBoxP2;
  } else {
    m_piece_type = wR;
    value = -50;
    pieceCurrentBlackBox = &rookBlackBoxP1;
    pieceCurrentWhiteBox = &rookWhiteBoxP1;
  }
}

Rook::~Rook() {}

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
