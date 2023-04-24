#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "sliding_moves.hpp"
#include "utils/defs.h"

template<Color color>
class Rook: public PieceBase {
public:
  explicit Rook(IMagicBitboardAttackType& mb) :
    PieceBase(color == BLACK ? bR : wR), rook_moves(mb) {}
  virtual ~Rook() {}
  bool is_legal_move(Move& m, Position& board) override {
    return rook_moves.get_sliding_attacks(m, board);
  }

  Bitboard get_attacks(Bitboard bb, Square sq) override {
    return rook_moves.get_attacks(bb, sq);
  }

private:
  SlidingMoves<color> rook_moves;
};

#endif /* ROOK_H */
