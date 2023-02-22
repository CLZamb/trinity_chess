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
  bool is_legal_move(Move &, BoardBitboard&) override;
  // U64 get_all_possible_positions(Move&, BoardBitboard &) override;

private:
  SlidingMoves<color> bishop_moves;
};

#endif /* ifndef BISHOP_H */

