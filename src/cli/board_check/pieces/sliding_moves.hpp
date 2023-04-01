#ifndef SLIDING_MOVES_H
#define SLIDING_MOVES_H

#include "magic_bitboard.h"
#include "board_bitboard.h"

template<Color color>
class SlidingMoves {
  public:
    SlidingMoves(const IMagicBitboardAttackType& at) : m_piece_attacks(at) {}
    virtual ~SlidingMoves() {}
    virtual U64 get_sliding_attacks(const Move& m, BoardBitboard& board) {
      U64 to = ONE << Move_Utils::get_to(m);
      const U64 own_color_pieces = board[color];
      return to & ~own_color_pieces & m_piece_attacks.get_attacks(board[BOTH], Move_Utils::get_from(m));
    };

  private:
    const IMagicBitboardAttackType& m_piece_attacks;
};

#endif // SLIDING_MOVES_H
