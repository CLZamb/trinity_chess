#include "bishop.h"
Bishop::Bishop(bool black, U64 bb)
  : Piece(black, bb) {
  if (black) {
    m_type = bB;
    p_cur_w_sq_drawing = &bishop_w_sq_p2;
    p_cur_b_sq_drawing = &bishop_b_sq_p2;
    m_value = 30;
  } else {
    m_type = wB;
    p_cur_w_sq_drawing = &bishop_w_sq_p1;
    p_cur_b_sq_drawing = &bishop_b_sq_p1;
    m_value = -30;
  }
}

Bishop::~Bishop() {}

box Bishop::bishop_w_sq_p2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m███(/)███\033[0m"},
    {"\033[7m███▙ ▟███\033[0m"},
    {"\033[7m███▀ ▀███\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Bishop::bishop_b_sq_p2 = {{
    {"█████████"},
    {"███(/)███"},
    {"███▙ ▟███"},
    {"███▀ ▀███"},
    {"█████████"},
}};

box Bishop::bishop_w_sq_p1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m███(/)███\033[0m"},
    {"\033[7m\033[1;37m███▙ ▟███\033[0m"},
    {"\033[7m\033[1;37m███▀ ▀███\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Bishop::bishop_b_sq_p1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m███(/)███\033[0m"},
    {"\033[1;37m███▙ ▟███\033[0m"},
    {"\033[1;37m███▀ ▀███\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
