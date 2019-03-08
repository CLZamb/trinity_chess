#include "king.h"
King::King(bool black, U64 bb)
  : Piece(black, bb) {
  if (black) {
    m_type = bK;
    p_cur_w_sq_drawing = &king_w_sq_p2;
    p_cur_b_sq_drawing = &king_b_sq_p2;
    m_value = 2000;
  } else {
    m_type = wK;
    p_cur_w_sq_drawing = &king_w_sq_p1;
    p_cur_b_sq_drawing = &king_b_sq_p1;
    m_value = -2000;
  }
}

King::~King() {}

box King::king_w_sq_p2 = {{
    {"░░▁ ✜ ▁░░"},
    {"░( ╲|╱ )░"},
    {"░░╲▁▁▁╱░░"},
    {"░[▁▁▁▁▁]░"},
    {"░░░░░░░░░"},
}};

box King::king_b_sq_p2 = {{
    {"██\033[0;32m▁ ✜ ▁\033[0m██"},
    {"█\033[0;32m( ╲|╱ )\033[0m█"},
    {"██\033[0;32m╲▁▁▁╱\033[0m██"},
    {"█\033[0;32m[▁▁▁▁▁]\033[0m█"},
    {"█████████"},
}};

box King::king_w_sq_p1 = {{
    {"\033[1;37m░░▁ ✜ ▁░░\033[0m"},
    {"\033[1;37m░( ╲|╱ )░\033[0m"},
    {"\033[1;37m░░╲▁▁▁╱░░\033[0m"},
    {"\033[1;37m░[▁▁▁▁▁]░\033[0m"},
    {"\033[1;37m░░░░░░░░░\033[0m"},
}};

box King::king_b_sq_p1 = {{
    {"\033[1;37m██▁ ✜ ▁██\033[0m"},
    {"\033[1;37m█( ╲|/ )█\033[0m"},
    {"\033[1;37m██╲▁▁▁╱██\033[0m"},
    {"\033[1;37m█[▁▁▁▁▁]█\033[0m"},
    {"\033[1;37m█████████\033[0m"},
}};
