#include "knight.h"
Knight::Knight(bool black, U64 bb) : Piece(black, bb) {
  if (black) {
    m_type = bN;
    p_cur_w_sq_drawing = &knight_w_sq_p2;
    p_cur_b_sq_drawing = &knight_b_sq_p2;
    m_value = 30;
  } else {
    m_type = wN;
    p_cur_w_sq_drawing = &knight_w_sq_p1;
    p_cur_b_sq_drawing = &knight_b_sq_p1;
    m_value = -30;
  }
}

Knight::~Knight() {}

box Knight::knight_w_sq_p2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m████ █ ██\033[0m"},
    {"\033[7m███    ██\033[0m"},
    {"\033[7m████   ██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Knight::knight_b_sq_p2 = {{
    {"█████████"},
    {"████ █ ██"},
    {"███    ██"},
    {"████   ██"},
    {"█████████"},
}};

box Knight::knight_w_sq_p1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m████ █ ██\033[0m"},
    {"\033[7m\033[1;37m███    ██\033[0m"},
    {"\033[7m\033[1;37m████   ██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Knight::knight_b_sq_p1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m████ █ ██\033[0m"},
    {"\033[1;37m███    ██\033[0m"},
    {"\033[1;37m████   ██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
