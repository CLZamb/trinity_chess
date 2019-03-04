#include "queen.h"
Queen::Queen(bool black, U64 bb) : Piece(black, bb) {
  if (black) {
    m_type = bQ;
    m_value = 90;
    p_cur_w_sq_drawing = &queen_w_sq_p2;
    p_cur_b_sq_drawing = &queen_b_sq_p2;
  } else {
    m_type = wQ;
    m_value = -90;
    p_cur_w_sq_drawing = &queen_w_sq_p1;
    p_cur_b_sq_drawing = &queen_b_sq_p1;
  }
}

Queen::~Queen() {}
std::string Queen::get_type() { return "queen"; }

box Queen::queen_w_sq_p2 = {{
    {"\033[7m█████████\033[0m"},
    {"\033[7m██ █ █ ██\033[0m"},
    {"\033[7m██     ██\033[0m"},
    {"\033[7m██     ██\033[0m"},
    {"\033[7m█████████\033[0m"},
}};

box Queen::queen_b_sq_p2 = {{
    {"█████████"},
    {"██ █ █ ██"},
    {"██     ██"},
    {"██     ██"},
    {"█████████"},
}};

box Queen::queen_w_sq_p1 = {{
    {"\033[7m\033[1;37m█████████\033[0m"},
    {"\033[7m\033[1;37m██ █ █ ██\033[0m"},
    {"\033[7m\033[1;37m██     ██\033[0m"},
    {"\033[7m\033[1;37m██     ██\033[0m"},
    {"\033[7m\033[1;37m█████████\033[0m"},
}};

box Queen::queen_b_sq_p1 = {{
    {"\033[1;37m█████████\033[0m"},
    {"\033[1;37m██ █ █ ██\033[0m"},
    {"\033[1;37m██     ██\033[0m"},
    {"\033[1;37m██     ██\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
