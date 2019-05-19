#include "piece.h"

Piece::Piece(Piecetype pct, U64 bb) :
  m_bitboard(bb), m_type(pct), black(IS_BLACK(pct)) {
  create_piece_drawing(pct);
  set_score(pct);
}

Piece::~Piece() {
  delete b_sq_drawing;
  delete w_sq_drawing;
}

void Piece::create_piece_drawing(Piecetype pct) {
  static const map<Piecetype, std::string> piece_drawing {
    {bP, "pawn"}, {bR, "rook"}, {bN, "knight"},
    {bB, "bishop"}, {bQ, "queen"}, {bK, "king"},
    {wP, "pawn"}, {wR, "rook"}, {wN, "knight"},
    {wB, "bishop"}, {wQ, "queen"}, {wK, "king"}
  };

  b_sq_drawing = new PieceDrawing(piece_drawing.at(pct));
  w_sq_drawing = new PieceDrawing(piece_drawing.at(pct));

  b_sq_drawing->addModifier(PieceDrawingMod::BG_INVERSE);

  if (black) {
    b_sq_drawing->addModifier(PieceDrawingMod::BG_B_BLACK);
    w_sq_drawing->addModifier(PieceDrawingMod::BG_B_BLACK);
  } else {
    b_sq_drawing->addModifier(PieceDrawingMod::FG_WHITE);
    w_sq_drawing->addModifier(PieceDrawingMod::FG_WHITE);
  }
}

void Piece::set_score(Piecetype pct) {
  static const map<Piecetype, int> piece_drawing {
    {bP, 10}, {bR, 50}, {bN, 30}, {bB, 30}, {bQ, 90}, {bK, 2000},
    {wP, -10}, {wR, -50}, {wN, -30}, {wB, -30}, {wQ, -90}, {wK, -2000}
  };

  m_value = piece_drawing.at(pct);
}

U64 Piece::get_bitboard() { return m_bitboard; }
box* Piece::get_drawing(bool is_black_square) {
  return is_black_square ?
    b_sq_drawing->get_drawing() : w_sq_drawing->get_drawing();
}
Piecetype Piece::get_type_and_color() { return m_type; }
bool Piece::is_black() { return black; }
int Piece::get_value() { return m_value; }
void Piece::clear_bit(int pos) { CLRBIT(m_bitboard, pos); }
void Piece::set_bit(int pos) { SETBIT(m_bitboard, pos); }
void Piece::make_move(int from, int to) { clear_bit(from); set_bit(to); }
void Piece::clear_bitboard() { m_bitboard = BLANK; }
