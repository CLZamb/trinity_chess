#include "rook.h"

template<Color color>
Rook<color>::Rook(IMagicBitboardAttackType& mb) :
  Piece(color == BLACK ? bR : wR), rook_moves(mb) {}

template<Color color>
Rook<color>::~Rook() {}

template<Color color>
bool Rook<color>::is_legal_move(Move& m, BoardBitboard& board) {
  return rook_moves.get_sliding_attacks(m, board);
}

// template<Color color>
// U64 Rook<color>::get_all_possible_positions(Move& ,BoardBitboard&) {
//   return EMPTY;
// }


