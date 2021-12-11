#include "headers/rook.h"

template<Color color>
Rook<color>::Rook(IMagicBitboardAttackType& mb) :
  Piece(color == BLACK ? bR : wR), rook_moves(mb) {}

template<Color color>
Rook<color>::~Rook() {}

template<Color color>
bool Rook<color>::is_legal_non_attack_move(const Move& m, const BoardBitboard& board) {
  return rook_moves.get_sliding_attacks(m, board);
}

template<Color color>
bool Rook<color>::is_legal_attack_move(const Move& m, const BoardBitboard& board) {
  return rook_moves.get_sliding_attacks(m, board);
}
