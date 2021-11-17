#include "headers/piece.h"
#include <ios>

Piece::Piece(const Piecetype& type):
              m_type(type),
              black(utils::check::is_black_piece(type)),
              p_piece_drawing(create_drawing(m_type)) {
}

Piece::~Piece() {}

PieceDrawing* Piece::create_drawing(const Piecetype& m_type) {
  drawing_builder.build_drawing(m_type);

  DrawingMod::Code piece_drawing_mod =
    this->black ? DrawingMod::BG_BLACK : DrawingMod::FG_WHITE;

  PieceDrawing* drawing = drawing_builder.get_drawing();
  drawing->set_drawing_mod(piece_drawing_mod);
  return drawing_builder.get_drawing();;
}

Box* Piece::get_box_drawing(bool is_in_black_square) {
  return p_piece_drawing->get_box_drawing(is_in_black_square);
}

Piecetype Piece::get_type_and_color() { return m_type; }

bool Piece::is_black() { 
  return black; 
}

bool Piece::is_black_piece(int pct) {
  return utils::check::is_black_piece(pct);
}

