#include "rook.h"
Rook::Rook(bool black, U64 bb) : Piece(black, bb) {
  m_value = 50;
  if (black) {
    m_type = bR;
    w_sq_drawing = new WhiteSquare(w_sq_drawing);

    p_cur_b_sq_drawing = b_sq_drawing->drawing();
    p_cur_w_sq_drawing = w_sq_drawing->drawing();
  } else {
    m_type = wR;
    w_sq_drawing = new WhiteSquare(w_sq_drawing);
    w_sq_drawing = new Player1(w_sq_drawing);
    b_sq_drawing = new Player1(b_sq_drawing);

    p_cur_b_sq_drawing = b_sq_drawing->drawing();
    p_cur_w_sq_drawing = w_sq_drawing->drawing();
  }
}

Rook::~Rook() {
  delete w_sq_drawing;
  delete b_sq_drawing;
}
