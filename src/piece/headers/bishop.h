#ifndef BISHOP_H
#define BISHOP_H 

#include "piece.h"
#include "magic_bitboard.h"
#include "sliding_moves.hpp"

template<Color color>
class Bishop : public Piece {
public:
  explicit Bishop(IMagicBitboardAttackType& m_bb);
  virtual ~Bishop();
  bool is_legal_non_attack_move(Move &, BoardBitboard&) override;
  bool is_legal_attack_move(Move &, BoardBitboard&) override;

private:
  SlidingMoves<color> bishop_moves;
};

#endif /* ifndef BISHOP_H */

