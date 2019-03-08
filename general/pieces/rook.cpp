#include "rook.h"
Rook::Rook(bool black, U64 bb) : Piece(black, bb) {
  if (black) {
    m_type = bR;
    p_cur_w_sq_drawing = &rook_w_sq_p2;
    p_cur_b_sq_drawing = &rook_b_sq_p2;
    m_value = 50;
  } else {
    m_type = wR;
    p_cur_w_sq_drawing = &rook_w_sq_p1;
    p_cur_b_sq_drawing = &rook_b_sq_p1;
    m_value = -50;
  }
}

Rook::~Rook() {}

box Rook::rook_w_sq_p2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m██▀█▀█▀██\033[0m"},
    {"\033[7m██▙   ▟██\033[0m"},
    {"\033[7m██▀   ▀██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Rook::rook_b_sq_p2 = {{
    {"█████████"},
    {"██▀█▀█▀██"},
    {"██▙   ▟██"},
    {"██▀   ▀██"},
    {"█████████"},
}};

box Rook::rook_w_sq_p1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m██▀█▀█▀██\033[0m"},
    {"\033[7m\033[1;37m██▙   ▟██\033[0m"},
    {"\033[7m\033[1;37m██▀   ▀██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Rook::rook_b_sq_p1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m██▀█▀█▀██\033[0m"},
    {"\033[1;37m██▙   ▟██\033[0m"},
    {"\033[1;37m██▀   ▀██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
