#include "pawn.h"

Pawn::Pawn(bool black, U64 bb)
    : Piece(black, bb) {
  if (black) {
    m_type = bP;
    m_value = 10;
    p_cur_w_sq_drawing = &pawn_w_sq_p2;
    p_cur_b_sq_drawing = &pawn_b_sq_p2;
  } else {
    m_type = wP;
    m_value = -10;
    p_cur_w_sq_drawing = &pawn_w_sq_p1;
    p_cur_b_sq_drawing = &pawn_b_sq_p1;
  }
}

Pawn::~Pawn() {}
std::string Pawn::get_type() { return "pawn"; }

box Pawn::pawn_w_sq_p2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m███( )███\033[0m"},
    {"\033[7m███▛ ▜███\033[0m"},
    {"\033[7m██▛   ▜██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Pawn::pawn_b_sq_p2 = {{
    {"█████████"},
    {"███( )███"},
    {"███▛ ▜███"},
    {"██▛   ▜██"},
    {"█████████"},
}};

box Pawn::pawn_w_sq_p1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m███( )███\033[0m"},
    {"\033[7m\033[1;37m███▛ ▜███\033[0m"},
    {"\033[7m\033[1;37m██▀   ▀██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Pawn::pawn_b_sq_p1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m███( )███\033[0m"},
    {"\033[1;37m███▛ ▜███\033[0m"},
    {"\033[1;37m██▀   ▀██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
