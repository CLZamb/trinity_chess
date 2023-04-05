#ifndef BISHOP_H
#define BISHOP_H 

#include "piece.h"
#include "sliding_moves.hpp"

template<Color color>
class Bishop : public Piece {
public:
  explicit Bishop(IMagicBitboardAttackType& m_bb) :
    Piece(color == BLACK ? bB : wB),
    bishop_moves(m_bb) {}

  virtual ~Bishop() {}
  bool is_legal_move(Move &m, BoardBitboard&board) override {
    return bishop_moves.get_sliding_attacks(m, board);
  }

private:
  SlidingMoves<color> bishop_moves;
};

#endif /* ifndef BISHOP_H */

