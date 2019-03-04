#include "piece.h"

Piece::Piece(bool is_black, U64 bb) : m_bitboard(bb), black(is_black) {
    for (int i = 0; i < 64; ++i) {
      SetMask[i] = 0ULL;
      ClearMask[i] = 0ULL;
    }

    for (int i = 0; i < 64; ++i) {
      SetMask[i] |= (1ULL << i);
      ClearMask[i] = ~SetMask[i];
    }
  }

Piece::~Piece() {}

U64 Piece::get_bitboard() { return m_bitboard; }
box* Piece::get_drawing_B_square() { return p_cur_b_sq_drawing; }
box* Piece::get_drawing_W_square() { return p_cur_w_sq_drawing; }
box* Piece::get_drawing_square(bool  white) {
  return white ? p_cur_b_sq_drawing : p_cur_w_sq_drawing;
}

Piecetype Piece::get_type_and_color() { return m_type; }
std::string Piece::get_type() { return ""; }
bool Piece::is_black() { return black; }
int Piece::get_value() { return m_value; }

void Piece::clear_bit(int pos) { CLRBIT(m_bitboard, pos); }
void Piece::set_bit(int pos) { SETBIT(m_bitboard, pos); }
void Piece::make_move(int from, int to) {
  CLRBIT(m_bitboard, from);
  SETBIT(m_bitboard, to);
}
