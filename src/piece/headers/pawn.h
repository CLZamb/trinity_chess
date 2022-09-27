#ifndef PAWN_H
#define PAWN_H

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

class BlackPawn :
    public PawnMove {
 public:
  U64 pawn_attack(int sq) override;
  U64 pawn_non_attack(int sq) override;
};

class WhitePawn :
    public PawnMove {
 public:
  U64 pawn_attack(int sq) override;
  U64 pawn_non_attack(int sq) override;
};

template<Color color>
class Pawn : public Piece {
 public:
  Pawn() : Piece(color == BLACK ? bP : wP) {
    if (color == BLACK) {
      pawn_moves = new BlackPawn();
    } else {
      pawn_moves = new WhitePawn();
    }
    init_masks();
  }
 
  virtual ~Pawn() {
    delete pawn_moves;
  }

  bool is_legal_move(Move &m, BoardBitboard& board) override {
    if (Move_Utils::get_captured_piece(m))
      return is_legal_attack_move(m, board);

    return is_legal_non_attack_move(m, board);
  }

 private:
  bool is_legal_attack_move(Move& m, BoardBitboard &board)  {
    U64 all_moves = BLANK;
    int from = Move_Utils::get_from(m);
    U64 to = ONE << Move_Utils::get_to(m);
    Piecetype captured = Move_Utils::get_captured_piece(m);
    const U64 opponent = board[utils::check::get_color_piece(captured)];

    all_moves |= m_attacks[from] & opponent;  // enemy is that square occ

    return all_moves & to;
  }

  bool is_legal_non_attack_move(Move& m, BoardBitboard &board) {
    int from = Move_Utils::get_from(m);
    U64 to = ONE << Move_Utils::get_to(m);
    const U64 free_squares = ~board[BOTH];
    return pawn_non_attack_mask(from) & free_squares & to;
  }

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

#endif /* PAWN_H */
