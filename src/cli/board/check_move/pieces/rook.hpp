#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "sliding_moves.hpp"

template<Color color>
class Rook : public Piece {
public:
  explicit Rook(IMagicBitboardAttackType& mb) :
    Piece(color == BLACK ? bR : wR), rook_moves(mb) {}
  virtual ~Rook() {}
  bool is_legal_move(Move& m, BoardBitboard& board) override {
    return rook_moves.get_sliding_attacks(m, board);
  }

private:
  SlidingMoves<color> rook_moves;
};

#endif /* ROOK_H */
