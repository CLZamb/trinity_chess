#ifndef SLIDING_MOVES_H
#define SLIDING_MOVES_H

#include "magic_bitboard.h"
#include "board/headers/defs.h"
#include "game/headers/move.hpp"
#include "board/headers/BoardBitboard.h"

template<Color color>
class SlidingMoves {
  public:
    SlidingMoves(const IMagicBitboardAttackType& at) : m_piece_attacks(at) {}
    virtual ~SlidingMoves() {}
    virtual U64 get_sliding_attacks(const Move& m, const BoardBitboard& board) {
      U64 to = ONE << Move_Utils::get_to(m);

      const U64 own_color_pieces = board.get_all_side_pieces(color == BLACK);
      return to & ~own_color_pieces & m_piece_attacks.get_attacks(board.get_all_board_pieces(), Move_Utils::get_from(m));
    };

    virtual U64 get_non_sliding_attacks(const Move& m, const BoardBitboard& board) {
      U64 to = ONE << Move_Utils::get_to(m);
      const U64 own_color_pieces = board.get_all_side_pieces(color == BLACK);
      return to & ~own_color_pieces & m_piece_attacks.get_attacks(board.get_all_board_pieces(), Move_Utils::get_from(m));
    };
  private:
    const IMagicBitboardAttackType& m_piece_attacks;
};

#endif // SLIDING_MOVES_H
