#include "headers/bishop.h"

template<Color color>
Bishop<color>::Bishop(IMagicBitboardAttackType& m_bb) :
  Piece(color == BLACK ? bB : wB),
  bishop_moves(m_bb)
{}

template<Color color>
Bishop<color>::~Bishop() {}

template<Color color>
bool Bishop<color>::is_legal_non_attack_move(const Move& m, const BoardBitboard& board) {
  return bishop_moves.get_sliding_attacks(m, board);
}

template<Color color>
bool Bishop<color>::is_legal_attack_move(const Move& m, const BoardBitboard& board) {
  return bishop_moves.get_sliding_attacks(m, board);
}
