#ifndef KING_H
#define KING_H

#include "piece.h"

template<Color color>
class King : public Piece {
  public:
    King();
    virtual ~King();
    bool is_legal_non_attack_move(const Move&, const BoardBitboard& board) override;
    bool is_legal_attack_move(const Move&, const BoardBitboard& board) override;
  private:
    U64 king_mask(int sq) {
      U64 king_mask = 0ULL;
      U64 from_sq = ONE << sq;

      king_mask |= bitUtility::shift<NORTH>(from_sq);
      king_mask |= bitUtility::shift<SOUTH>(from_sq);
      king_mask |= bitUtility::shift<EAST>(from_sq);
      king_mask |= bitUtility::shift<WEST>(from_sq);
      king_mask |= bitUtility::shift<NORTH_EAST>(from_sq);
      king_mask |= bitUtility::shift<NORTH_WEST>(from_sq);
      king_mask |= bitUtility::shift<SOUTH_EAST>(from_sq);
      king_mask |= bitUtility::shift<SOUTH_WEST>(from_sq);
      return king_mask;
    }

    void _init_moves() {
      for (int sq = 0; sq < utils::constant::ksquares; sq++) {
        m_attacks[sq] = king_mask(sq);
      }
    }
};

#endif /* KING_H */