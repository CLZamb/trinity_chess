#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

template<Color color>
class Knight : public Piece {
  public:
    Knight() : Piece(color == BLACK ? bN : wN) {
      _init_moves();
    }

    virtual ~Knight() {}

    bool is_legal_move(Move& m, BoardBitboard& board) override {
      SquareIndices from = Move_Utils::get_from(m);
      U64 to = ONE << Move_Utils::get_to(m);
      Piecetype captured = Move_Utils::get_captured_piece(m);
      U64 free_squares = ~board[BOTH];

      if (captured) {
        free_squares |= board[utils::check::get_color_piece(captured)];
      }

      return m_attacks[from] & to & free_squares;
    }
    // U64 get_all_possible_positions(Move& m, BoardBitboard&) override;

  private:
    U64 knight_mask(int sq) {
      U64 result = BLANK;
      U64 from_sq = ONE << sq;
      U64 shift = BLANK;

      shift = bitUtility::shift<SOUTH_SOUTH>(from_sq);
      shift = bitUtility::shift<WEST>(shift);
      if (shift & NOT_H_FILE)
        result |= shift & NOT_H_FILE;

      shift = bitUtility::shift<SOUTH_SOUTH>(from_sq);
      shift = bitUtility::shift<EAST>(shift);
      if (shift & NOT_A_FILE)
        result |= shift & NOT_A_FILE;

      shift = bitUtility::shift<SOUTH_WEST>(from_sq);
      shift = bitUtility::shift<WEST>(shift);
      if (shift & NOT_GH_FILE)
        result |= shift & NOT_GH_FILE;

      shift = bitUtility::shift<SOUTH_EAST>(from_sq);
      shift = bitUtility::shift<EAST>(shift);
      if (shift & NOT_AB_FILE)
        result |= shift & NOT_AB_FILE;

      shift = bitUtility::shift<NORTH_NORTH>(from_sq);
      shift = bitUtility::shift<EAST>(shift);
      if (shift & NOT_A_FILE)
        result |= shift & NOT_A_FILE;

      shift = bitUtility::shift<NORTH_NORTH>(from_sq);
      shift = bitUtility::shift<WEST>(shift);
      if (shift & NOT_H_FILE)
        result |= shift & NOT_H_FILE;

      shift = bitUtility::shift<NORTH_EAST>(from_sq);
      shift = bitUtility::shift<EAST>(shift);
      if (shift & NOT_AB_FILE)
        result |= shift & NOT_AB_FILE;

      shift = bitUtility::shift<NORTH_WEST>(from_sq);
      shift = bitUtility::shift<WEST>(shift);
      if (shift & NOT_GH_FILE)
        result |= shift & NOT_GH_FILE;

      return result;
    }

    void _init_moves() {
      for (int sq = 0; sq < utils::constant::ksquares; sq++) {
        m_attacks[sq] = knight_mask(sq);
      }
    }
};

#endif /* KNIGHT_H */
