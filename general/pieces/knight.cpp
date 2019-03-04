#include "knight.h"
Knight::Knight(bool black, U64 bb) : Piece(black, bb) {
  if (black) {
    m_type = bN;
    m_value = 30;
    p_cur_w_sq_drawing = &knight_w_sq_p2;
    p_cur_b_sq_drawing = &knight_b_sq_p2;
  } else {
    m_type = wN;
    m_value = -30;
    p_cur_w_sq_drawing = &knight_w_sq_p1;
    p_cur_b_sq_drawing = &knight_b_sq_p1;
  }
}

Knight::~Knight() {}
std::string Knight::get_type() { return "knight"; }

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
