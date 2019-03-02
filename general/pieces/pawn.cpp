#include "pawn.h"

Pawn::Pawn(std::string pieceColor, U64 bb)
    : Piece(pieceColor, bb) {
  if (pieceColor == "black") {
    m_piece_type = bP;
    value = 10;
    pieceCurrentBlackBox = &PawnBlackBoxP2;
    pieceCurrentWhiteBox = &PawnWhiteBoxP2;
    oneSpaceForward = DOWN;
  } else {
    m_piece_type = wP;
    value = -10;
    pieceCurrentBlackBox = &PawnBlackBoxP1;
    pieceCurrentWhiteBox = &PawnWhiteBoxP1;
    oneSpaceForward = UP;
  }
}

Pawn::~Pawn() {}

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
