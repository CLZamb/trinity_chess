#ifndef KING_H
#define KING_H

#include <unordered_map>

#include "piece.h"

template <Color color>
class King : public PieceBase {
 public:
  King() : PieceBase(color == BLACK ? bK : wK) { _init_moves(); }
  virtual ~King() {}
  bool is_legal_move(Move &m, Position &board) override {
    Square from = MoveUtils::get_from(m);
    Bitboard to = ONE << MoveUtils::get_to(m);
    Bitboard free_squares = ~board.get_occupied_squares_as_bitboard();
    Piece captured = MoveUtils::get_captured_piece(m);

    if (MoveUtils::can_castle(m)) {
      return check_legal_castle(m, board);
    }

    if (captured) {
      free_squares |= board.get_occupied_side_as_bitboard(utils::check::get_color_piece(captured));
    }

    return m_attacks[from] & to & free_squares;
  }

  static Bitboard king_mask(unsigned int sq) {
    Bitboard king_mask = 0ULL;
    Bitboard from_sq = ONE << sq;

    king_mask |= bitUtility::shift<bitUtility::NORTH>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::SOUTH>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::EAST>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::WEST>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::NORTH_EAST>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::NORTH_WEST>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::SOUTH_EAST>(from_sq);
    king_mask |= bitUtility::shift<bitUtility::SOUTH_WEST>(from_sq);
    return king_mask;
  }

  Bitboard get_attacks(Bitboard bb, Square sq) override {
    return king_mask(sq) & bb;
  }

 private:
  struct KingCastle {
    CastleSquares _from;
    CastleSquares _to;
    std::vector<Square> free_squares;
  };

  const std::unordered_map<CastlePermission, typename King<color>::KingCastle> m_kc{
      {NO_CASTLING, {NO_CASTLE_POS, NO_CASTLE_POS, {}}},
      {WKCA, {WK_CA_INITIAL_POS, WK_CA_KING_SIDE_END_POS, {F1, G1}}},
      {WQCA, {WK_CA_INITIAL_POS, WK_CA_QUEEN_SIDE_END_POS, {B1, C1, D1}}},
      {BKCA, {BK_CA_INITIAL_POS, BK_CA_KING_SIDE_END_POS, {F8, G8}}},
      {BQCA, {BK_CA_INITIAL_POS, BK_CA_QUEEN_SIDE_END_POS, {B8, C8, D8}}},
  };

  bool check_legal_castle(const Move &m, Position &b) {
    Square from = MoveUtils::get_from(m);
    Square to = MoveUtils::get_to(m);
    const KingCastle &kc = m_kc.at(MoveUtils::get_castle_permission(m));

    if (from != static_cast<Square>(kc._from)) {
      return false;
    }
    if (to != static_cast<Square>(kc._to)) {
      return false;
    }

    for (const auto pos : kc.free_squares) {
      if (b.is_occupied(pos)) {
        return false;
      }
    }

    return true;
  }

  void _init_moves() {
    for (unsigned int sq = 0; sq < utils::constant::ksquares; sq++) {
      m_attacks[sq] = king_mask(sq);
    }
  }
};

#endif /* KING_H */
