#include "bishop.h"
Bishop::Bishop(std::string pieceColor, U64 bb)
  : Piece(pieceColor, bb) {
  if (pieceColor == "black") {
    m_piece_type = bB;
    value = 30;
    pieceCurrentBlackBox = &bishopBlackBoxP2;
    pieceCurrentWhiteBox = &bishopWhiteBoxP2;
  } else {
    m_piece_type = wB;
    value = -30;
    pieceCurrentBlackBox = &bishopBlackBoxP1;
    pieceCurrentWhiteBox = &bishopWhiteBoxP1;
  }
}

Bishop::~Bishop() {}

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
