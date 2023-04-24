#ifndef QUEEN_H
#define QUEEN_H 

#include "piece.h"
#include "sliding_moves.hpp"

template<Color color>
class Queen : public PieceBase {
public:
  explicit Queen(IMagicBitboardAttackType& m_bb) : 
    PieceBase(color == BLACK ? bQ : wQ), queen_moves(m_bb) {}
  virtual ~Queen() {}
  bool is_legal_move(Move &m, Position& board) override {
    return queen_moves.get_sliding_attacks(m, board);
  }

  Bitboard get_attacks(Bitboard bb, Square sq) override {
    return queen_moves.get_attacks(bb, sq);
  }

private:
  SlidingMoves<color> queen_moves;
};

#endif /* ifndef QUEEN_H */
