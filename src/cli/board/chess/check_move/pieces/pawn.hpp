#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

template <Color C>
constexpr Bitboard pawn_attacks_bb(Bitboard b) {
  return C == WHITE ? bitUtility::shift<bitUtility::NORTH_WEST>(b) |
                          bitUtility::shift<bitUtility::NORTH_EAST>(b)
                    : bitUtility::shift<bitUtility::SOUTH_WEST>(b) |
                          bitUtility::shift<bitUtility::SOUTH_EAST>(b);
}

class PawnMove {
 public:
  virtual ~PawnMove() {}
  virtual Bitboard pawn_attack(int) = 0;
  virtual Bitboard pawn_non_attack(int) = 0;
};

class BlackPawn : public PawnMove {
 public:
  Bitboard pawn_attack(int sq) override {
    Bitboard from_sq = ONE << sq;
    Bitboard result = BLANK;

    result = bitUtility::shift<bitUtility::SOUTH_EAST>(from_sq);
    result |= bitUtility::shift<bitUtility::SOUTH_WEST>(from_sq);
    return result;
  }
  Bitboard pawn_non_attack(int sq) override {
    Bitboard from_sq = ONE << sq;
    Bitboard result = BLANK;
    Bitboard forward_one_sq = BLANK;
    Bitboard forward_two_sq = BLANK;

    forward_one_sq = bitUtility::shift<bitUtility::SOUTH>(from_sq);
    forward_two_sq |= bitUtility::shift<bitUtility::SOUTH>(forward_one_sq & ROWMASK[5]);
    result = forward_one_sq | forward_two_sq;
    return result;
  }
};

class WhitePawn : public PawnMove {
 public:
  Bitboard pawn_attack(int sq) override {
    Bitboard from_sq = ONE << sq;
    Bitboard result = BLANK;
    result = bitUtility::shift<bitUtility::NORTH_WEST>(from_sq);
    result |= bitUtility::shift<bitUtility::NORTH_EAST>(from_sq);
    return result;
  }
  Bitboard pawn_non_attack(int sq) override {
    Bitboard from_sq = ONE << sq;
    Bitboard result = BLANK;
    Bitboard forward_one_sq = BLANK;
    Bitboard forward_two_sq = BLANK;

    forward_one_sq = bitUtility::shift<bitUtility::NORTH>(from_sq);
    forward_two_sq |= bitUtility::shift<bitUtility::NORTH>(forward_one_sq & ROWMASK[2]);
    result = forward_one_sq | forward_two_sq;
    return result;
  }
};

template <Color color>
class Pawn : public PieceBase {
 public:
  Pawn() : PieceBase(color == BLACK ? bP : wP) {
    if (color == BLACK) {
      pawn_moves = new BlackPawn();
    } else {
      pawn_moves = new WhitePawn();
    }
    init_masks();
  }

  virtual ~Pawn() { delete pawn_moves; }

  bool is_legal_move(Move &m, Position &board) override {
    if (MoveUtils::is_en_passand(m)) {
      return is_legal_en_passant_move(m);
    }

    if (MoveUtils::get_captured_piece(m)) {
      return is_legal_attack_move(m, board);
    }

    return is_legal_non_attack_move(m, board);
  }

  bool is_legal_en_passant_move(const Move &m) {
    Square sq = MoveUtils::get_from(m);
    Bitboard from_sq = ONE << sq;
    Bitboard to_sq = ONE << MoveUtils::get_to(m);
    Bitboard attack_moves = pawn_moves->pawn_attack(sq);
    Bitboard row_mask = (color == WHITE) ? ROWMASK[4] : ROWMASK[3];
    return (row_mask & from_sq) && (to_sq & attack_moves);
  }

  static bool is_first_move(const Move &m) {
    Piece piece = MoveUtils::get_piece(m);
    Bitboard from_sq = ONE << MoveUtils::get_from(m);

    if (piece != bP && piece != wP) {
      return false;
    }

    if (color == BLACK) {
      if (from_sq & ROWMASK[6]) {
        return true;
      }
    } else {
      if (from_sq & ROWMASK[1]) {
        return true;
      }
    }

    return false;
  }

  static bool is_promotion(const Move &m) {
    Piece piece = MoveUtils::get_piece(m);
    Bitboard to_sq = ONE << MoveUtils::get_to(m);

    if (piece != bP && piece != wP) {
      return false;
    }

    if (color == BLACK) {
      if (to_sq & ROWMASK[0]) {
        return true;
      }
    } else {
      if (to_sq & ROWMASK[7]) {
        return true;
      }
    }

    return false;
  }

  static bool is_double_forward_move(const Move &m) {
    Piece piece = MoveUtils::get_piece(m);
    Bitboard to_sq = ONE << MoveUtils::get_to(m);

    if (piece != bP && piece != wP) {
      return false;
    }

    if (color == BLACK) {
      if (to_sq & ROWMASK[4]) {
        return true;
      }
    } else {
      if (to_sq & ROWMASK[3]) {
        return true;
      }
    }

    return false;
  }

  Bitboard get_attacks(Bitboard bb, Square sq) override {
    return (ONE << sq) | (m_attacks[sq] & bb);
  }

 private:
  bool is_legal_attack_move(Move &m, Position &board) {
    Bitboard all_moves = BLANK;
    Square from = MoveUtils::get_from(m);
    Bitboard to = ONE << MoveUtils::get_to(m);
    Piece captured = MoveUtils::get_captured_piece(m);
    const Bitboard opponent = board.get_occupied_side_as_bitboard(utils::check::get_color_piece(captured));

    all_moves |= m_attacks[from] & opponent;   // enemy is in that square
    return all_moves & to;
  }

  bool is_legal_non_attack_move(Move &m, Position &board) {
    Square from = MoveUtils::get_from(m);
    Bitboard to = ONE << MoveUtils::get_to(m);
    const Bitboard free_squares = ~board.get_occupied_squares_as_bitboard();
    return pawn_non_attack_mask(from) & free_squares & to;
  }

  void init_masks() {
    for (int sq = 0; sq < utils::constant::ksquares; sq++) {
      m_attacks[sq] = pawn_attack_mask(sq);
    }
  }

  Bitboard pawn_attack_mask(int sq) {
    Bitboard pawn_mask = BLANK;
    pawn_mask = pawn_moves->pawn_attack(sq);
    return pawn_mask;
  }

  Bitboard pawn_non_attack_mask(int from_sq) {
    Bitboard result = ONE << from_sq;
    result = pawn_moves->pawn_non_attack(from_sq);
    return result;
  }

  Bitboard pawn_attacks_bb;
  PawnMove *pawn_moves;
};

#endif /* PAWN_H */
