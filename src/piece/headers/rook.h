#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "magic_bitboard.h"
#include "sliding_moves.hpp"

template<Color color>
class Rook : public Piece {
public:
  explicit Rook(IMagicBitboardAttackType& mb);
  virtual ~Rook();
  bool is_legal_move(Move& m, BoardBitboard&) override;

private:
  SlidingMoves<color> rook_moves;
};

#endif /* ROOK_H */
