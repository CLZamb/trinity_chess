#include "bishop.h"
Bishop::Bishop(bool black, U64 bb)
  : Piece(black, bb) {
  if (black) {
    m_type = bB;
    m_value = 30;
    p_cur_w_sq_drawing = &bishop_w_sq_p2;
    p_cur_b_sq_drawing = &bishop_b_sq_p2;
  } else {
    m_type = wB;
    m_value = -30;
    p_cur_w_sq_drawing = &bishop_w_sq_p1;
    p_cur_b_sq_drawing = &bishop_b_sq_p1;
  }
}

Bishop::~Bishop() {}
std::string Bishop::get_type() { return "bishop"; }

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
