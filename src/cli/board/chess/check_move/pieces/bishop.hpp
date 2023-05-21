#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "sliding_moves.hpp"

template <Color color>
class Bishop : public PieceBase {
 public:
  explicit Bishop(IMagicBitboardAttackType &m_bb)
      : PieceBase(color == BLACK ? bB : wB), bishop_moves(m_bb) {}

  virtual ~Bishop() {}
  bool is_legal_move(Move &m, Position &board) override {
    return bishop_moves.get_sliding_attacks(m, board);
  }

  Bitboard get_attacks(Bitboard bb, Square sq) override {
    return bishop_moves.get_attacks(bb, sq);
  }

 private:
  SlidingMoves<color> bishop_moves;
};

#endif /* ifndef BISHOP_H */
