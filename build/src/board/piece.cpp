#include "headers/piece.h"

Piece::Piece(Piecetype pct) :
  black(utils::check::is_black_piece(pct)), m_type(pct) {
    create_drawing(utils::get_piece_str_name_from_piecetype(pct));
}

Piece::~Piece() {
  delete white_square_drawing;
  delete black_square_drawing;
}
//
void Piece::create_drawing(string piece_type) {
  black_square_drawing = new Drawing(piece_type);
  white_square_drawing = new Drawing(piece_type);

  DrawingMod::Code piece_drawing_mod =
    black ? DrawingMod::BG_BLACK : DrawingMod::FG_WHITE;

  black_square_drawing->addModifier(DrawingMod::BG_INVERSE);
  black_square_drawing->addModifier(piece_drawing_mod);
  white_square_drawing->addModifier(piece_drawing_mod);
}

box* Piece::get_drawing(bool is_black_square) {
  return is_black_square ?
    black_square_drawing->get_drawing() : white_square_drawing->get_drawing();
}

Piecetype Piece::get_type_and_color() { return m_type; }

bool Piece::is_black() { return black; }
