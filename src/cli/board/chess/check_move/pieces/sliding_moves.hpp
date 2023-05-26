#ifndef SLIDING_MOVES_H
#define SLIDING_MOVES_H

#include "board/chess/position/position.h"
#include "magic_bitboard.h"
#include "utils/defs.h"

template <Color color>
class SlidingMoves {
 public:
  explicit SlidingMoves(const IMagicBitboardAttackType &at)
      : m_piece_attacks(at) {}
  virtual ~SlidingMoves() {}
  virtual Bitboard get_sliding_attacks(const Move &move, Position &position) {
    Bitboard to = ONE << MoveUtils::get_to(move);
    const Bitboard own_color_pieces =
        position.get_occupied_side_as_bitboard(color);
    return to & ~own_color_pieces &
           m_piece_attacks.get_attacks(
               position.get_occupied_squares_as_bitboard(),
               MoveUtils::get_from(move));
  };
  virtual Bitboard get_attacks(Bitboard bb, Square sq) {
    return m_piece_attacks.get_attacks(bb, sq);
  }

 private:
  const IMagicBitboardAttackType &m_piece_attacks;
};

#endif   // SLIDING_MOVES_H
