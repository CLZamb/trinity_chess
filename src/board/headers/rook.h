#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

template<Color C>
constexpr U64 pawn_attacks_bb(U64 b) {
  return C == WHITE ? shift<NORTH_WEST>(b) | shift<NORTH_EAST>(b)
                    : shift<SOUTH_WEST>(b) | shift<SOUTH_EAST>(b);
}

class PawnMove {
 public:
    virtual ~PawnMove() {}
    virtual U64 pawn_attack(int) = 0;
    virtual U64 pawn_non_attack(int) = 0;
};

class BlackRook :
    public PawnMove {
 public:
  U64 pawn_attack(int sq) override {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;

    result = shift<SOUTH_EAST>(from_sq);
    result |= shift<SOUTH_WEST>(from_sq);
    return result;
  }

  U64 pawn_non_attack(int sq) override {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;

    result = shift<SOUTH>(from_sq);
    result |= shift<SOUTH>(result & ROWMASK[5]);
    return result;
  }
};

class WhiteRook :
    public PawnMove {
 public:
  U64 pawn_attack(int sq) override {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;
    result = shift<NORTH_WEST>(from_sq);
    result |= shift<NORTH_EAST>(from_sq);
    return result;
  }

  U64 pawn_non_attack(int sq) override {
    U64 from_sq = ONE << sq;
    U64 result = BLANK;

    result = shift<NORTH>(from_sq);
    result |= shift<NORTH>(result & ROWMASK[2]);
    return result;
  }
};


template<Color color>
class Rook : public Piece {
 public:
  Rook() : Piece(color == BLACK ? bR : wR) {
    if (color == BLACK) {
      pawn_moves = new BlackRook();
    } else {
      pawn_moves = new WhiteRook();
    }

    init_masks();
  }

  virtual ~Rook() {
    delete pawn_moves;
  }

  bool is_legal_move(const Move& m) override  {
    U64 all_moves = BLANK;
    int square_from = m.get_from();

    if (m.get_captured_piece()) {
      all_moves |= m_attacks[square_from];  // enemy is that square occ
    }

    all_moves |= pawn_non_attack_mask(square_from);

    U64 to = ONE << m.get_to();
    return all_moves & to;
  }

 private:
  void init_masks() {
    for (int sq = 0; sq < utils::constant::ksquares; sq++)
      m_attacks[sq] = pawn_attack_mask(sq);
  }

  U64 pawn_attack_mask(int sq) {
    U64 pawn_mask = BLANK;
    pawn_mask = pawn_moves->pawn_attack(sq);
    return pawn_mask;
  }

  U64 pawn_non_attack_mask(int from_sq) {
    U64 result = ONE << from_sq;
    result = pawn_moves->pawn_non_attack(from_sq);
    return result;
  }

  U64 pawn_attacks_bb;
  PawnMove* pawn_moves;
};

#endif /* ROOK_H */
