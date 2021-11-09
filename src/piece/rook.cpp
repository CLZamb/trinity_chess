#include "headers/rook.h"

template<Color color>
Rook<color>::Rook(const MagicBitboard& m_bb) :
  Piece(color == BLACK ? bR : wR),
  m_bb{&m_bb} {}

template<Color color>
Rook<color>::~Rook() {}

template<Color color>
bool Rook<color>::is_legal_move(const Move& m) {
  if (m_bb == nullptr) return false;

  U64 all_moves = BLANK;
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  all_moves = m_bb->rook_attacks(all_moves, from);
  return all_moves & to;
}
