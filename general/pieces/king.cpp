#include "king.h"
King::King(bool black, U64 bb)
  : Piece(black, bb) {
  m_value = 20000;

  if (black) {
    m_type = bK;

    p_cur_b_sq_drawing = b_sq_drawing->drawing();
    p_cur_w_sq_drawing = w_sq_drawing->drawing();
  } else {
    m_type = wK;

    w_sq_drawing = new Player1(w_sq_drawing);
    b_sq_drawing = new Player1(b_sq_drawing);

    p_cur_b_sq_drawing = b_sq_drawing->drawing();
    p_cur_w_sq_drawing = w_sq_drawing->drawing();
  }
}

King::~King() {
  delete w_sq_drawing;
  delete b_sq_drawing;
}
