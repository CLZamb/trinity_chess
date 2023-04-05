#ifndef QUEEN_H
#define QUEEN_H 

#include "piece.h"
#include "sliding_moves.hpp"

template<Color color>
class Queen : public Piece {
public:
  explicit Queen(IMagicBitboardAttackType& m_bb) : 
    Piece(color == BLACK ? bQ : wQ), queen_moves(m_bb) {}
  virtual ~Queen() {}
  bool is_legal_move(Move &m, BoardBitboard& board) override {
    return queen_moves.get_sliding_attacks(m, board);
  }

private:
  SlidingMoves<color> queen_moves;
};

#endif /* ifndef QUEEN_H */
