#ifndef SLIDING_MOVES_H
#define SLIDING_MOVES_H

#include "board/board_representation/position.hpp"
#include "magic_bitboard.h"
#include "utils/defs.h"

template<Color color>
class SlidingMoves {
 public:
  SlidingMoves(const IMagicBitboardAttackType& at) : m_piece_attacks(at) {}
  virtual ~SlidingMoves() {}
  virtual Bitboard get_sliding_attacks(const Move& m, Position& position) {
    Bitboard to = ONE << MoveUtils::get_to(m);
    const Bitboard own_color_pieces = position[color];
    return to & ~own_color_pieces & m_piece_attacks.get_attacks(position[BOTH], MoveUtils::get_from(m));
  };
  virtual Bitboard get_attacks(Bitboard bb, Square sq)  {
    return m_piece_attacks.get_attacks(bb, sq);
  }

 private:
  const IMagicBitboardAttackType& m_piece_attacks;
};

#endif // SLIDING_MOVES_H
