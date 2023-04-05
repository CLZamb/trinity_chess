#ifndef KING_H
#define KING_H

#include <unordered_map>
#include "piece.h"

using std::unordered_map;
using std::vector;

template<Color color>
class King : public Piece {
 public:
  King() : Piece(color == BLACK ? bK : wK) {
    _init_moves();
  }
  virtual ~King() {}
  bool is_legal_move(Move& m, BoardBitboard& board) override {
    SquareIndices from = Move_Utils::get_from(m);
    U64 to = ONE << Move_Utils::get_to(m);
    U64 free_squares = ~board[BOTH];
    Piecetype captured = Move_Utils::get_captured_piece(m);

    if (Move_Utils::can_castle(m))
      return check_legal_castle(m, board);

    if (captured) 
      free_squares |= board[utils::check::get_color_piece(captured)];

    return m_attacks[from] & to & free_squares;
  }

  static U64 king_mask(unsigned int sq) {
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

 private:
  struct KingCastle {
    CastleSquares _from;
    CastleSquares _to;
    vector<SquareIndices> free_squares;
  };

  const unordered_map<CastlePermission, typename King<color>::KingCastle> m_kc {
    {NO_CASTLING, {NO_CASTLE_POS, NO_CASTLE_POS, {}}},
    {WKCA ,{WK_CA_INITIAL_POS, WK_CA_KING_SIDE_END_POS,  {F1, G1}}},
    {WQCA ,{WK_CA_INITIAL_POS, WK_CA_QUEEN_SIDE_END_POS, {B1, C1, D1}}},
    {BKCA ,{BK_CA_INITIAL_POS, BK_CA_KING_SIDE_END_POS,  {F8, G8}}},
    {BQCA ,{BK_CA_INITIAL_POS, BK_CA_QUEEN_SIDE_END_POS, {B8, C8, D8}}},
  };

  bool check_legal_castle(const Move& m, BoardBitboard &b) {
    SquareIndices from = Move_Utils::get_from(m);
    SquareIndices to = Move_Utils::get_to(m);
    const KingCastle &kc = m_kc.at(Move_Utils::get_castle_permission(m));

    if (from != static_cast<SquareIndices>(kc._from)) return false;
    if (to != static_cast<SquareIndices>(kc._to))  return false;

    for (const auto pos : kc.free_squares)
    if (b.is_occupied_at_pos(pos)) return false;

    return true;
  }

  void _init_moves() {
    for (unsigned int sq = 0; sq < utils::constant::ksquares; sq++) {
      m_attacks[sq] = king_mask(sq);
    }
  }
};

#endif /* KING_H */
