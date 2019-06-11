#include "piece.h"

Piece::Piece(Piecetype pct, U64 bb) :
  m_bitboard(bb), m_type(pct), black(utils::check::is_black_piece(pct)) {
  create_piece_drawing(pct);
  set_score(pct);
}

Piece::~Piece() {
  delete b_sq_drawing;
  delete w_sq_drawing;
}

void Piece::create_piece_drawing(Piecetype pct) {
  b_sq_drawing = new PieceDrawing(piece_str_name.at(pct));
  w_sq_drawing = new PieceDrawing(piece_str_name.at(pct));
  b_sq_drawing->addModifier(DrawingMod::BG_INVERSE);

  if (black) {
    b_sq_drawing->addModifier(DrawingMod::BG_BLACK);
    w_sq_drawing->addModifier(DrawingMod::BG_BLACK);
  } else {
    b_sq_drawing->addModifier(DrawingMod::FG_WHITE);
    w_sq_drawing->addModifier(DrawingMod::FG_WHITE);
  }
}

void Piece::set_score(Piecetype pct) {
  m_material_score = utils::constant::piece_material_score[pct];
}

U64 Piece::get_bitboard() { return m_bitboard; }
box* Piece::get_drawing(bool is_black_square) {
  return is_black_square ?
    b_sq_drawing->get_drawing() : w_sq_drawing->get_drawing();
}
Piecetype Piece::get_type_and_color() { return m_type; }
bool Piece::is_black() { return black; }
void Piece::clear_bit(SquareIndices pos) {
  bitUtility::clear_bit(&m_bitboard, pos);
}
void Piece::set_bit(SquareIndices pos) {
  bitUtility::set_bit(&m_bitboard, pos);
}
void Piece::make_move(SquareIndices from, SquareIndices to) {
  clear_bit(from); set_bit(to);
}
void Piece::clear_bitboard() { m_bitboard = BLANK; }
int Piece::get_material_score() {
  return (bitUtility::count_1s(m_bitboard) * m_material_score);
}
