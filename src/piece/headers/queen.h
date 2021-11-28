#ifndef QUEEN_H
#define QUEEN_H 

#include "piece.h"
#include "magic_bitboard.h"
#include "sliding_moves.hpp"

template<Color color>
class Queen : public Piece {
public:
  explicit Queen(IMagicBitboardAttackType& m_bb);
  virtual ~Queen();
  bool is_legal_non_attack_move(const Move&, const BoardBitboard& board) override;
  bool is_legal_attack_move(const Move&, const BoardBitboard& board) override;

private:
  SlidingMoves<color> queen_moves;
};

#endif /* ifndef QUEEN_H */
