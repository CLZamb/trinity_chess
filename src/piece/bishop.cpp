#include "headers/bishop.h"

template<Color color>
Bishop<color>::Bishop(const MagicBitboard& m_bb) :
  Piece(color == BLACK ? bB : wB),
  m_bb{&m_bb} {}

template<Color color>
Bishop<color>::~Bishop() {}

template<Color color>
bool Bishop<color>::is_legal_move(const Move& m) {
  if (m_bb == nullptr) return false;

  U64 all_moves = BLANK;
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  all_moves = m_bb->bishop_attacks(all_moves, from);
  return all_moves & to;
}
