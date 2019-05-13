#include "pawn.h"

Pawn::Pawn(bool black, U64 bb)
    : Piece(black, bb) {
  m_value = 10;

  if (black) {
    m_type = bP;

    p_cur_b_sq_drawing = b_sq_drawing->drawing();
    p_cur_w_sq_drawing = w_sq_drawing->drawing();
  } else {
    m_type = wP;

    w_sq_drawing = new Player1(w_sq_drawing);
    b_sq_drawing = new Player1(b_sq_drawing);

    p_cur_b_sq_drawing = b_sq_drawing->drawing();
    p_cur_w_sq_drawing = w_sq_drawing->drawing();
  }
}

Pawn::~Pawn() {
  delete w_sq_drawing;
  delete b_sq_drawing;
}
