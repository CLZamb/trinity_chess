#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

template<Color color>
class Knight : public Piece {
  public:
    Knight();
    virtual ~Knight();
    bool is_legal_move(Move& m, BoardBitboard& ) override;

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
