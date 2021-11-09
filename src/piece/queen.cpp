#include "headers/queen.h"

template<Color color>
Queen<color>::Queen(const MagicBitboard& m_bb) :
  Piece(color == BLACK ? bQ : wQ),
  m_bb{&m_bb} {}

template<Color color>
Queen<color>::~Queen() {}

template<Color color>
bool Queen<color>::is_legal_move(const Move& m) {
  if (m_bb == nullptr) return false;

  U64 all_moves = BLANK;
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  all_moves = m_bb->queen_attacks(all_moves, from);
  return all_moves & to;
}
