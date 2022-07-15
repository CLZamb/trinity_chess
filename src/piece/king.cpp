#include "headers/king.h"
#include "board/headers/defs.h"

template <Color color>
const unordered_map<CastlePermission, typename King<color>::KingCastle> King<color>::m_kc {
  {NO_CASTLING, {NO_CASTLE_POS, NO_CASTLE_POS, {}}},
  {WKCA ,{WK_CA_INITIAL_POS, WK_CA_KING_SIDE_END_POS,  {F1, G1}}},
  {WQCA ,{WK_CA_INITIAL_POS, WK_CA_QUEEN_SIDE_END_POS, {B1, C1, D1}}},
  {BKCA ,{BK_CA_INITIAL_POS, BK_CA_KING_SIDE_END_POS,  {F8, G8}}},
  {BQCA ,{BK_CA_INITIAL_POS, BK_CA_QUEEN_SIDE_END_POS, {B8, C8, D8}}},
};

template <Color color> King<color>::King() : Piece(color == BLACK ? bK : wK) {
  _init_moves();
}

template <Color color> King<color>::~King() {}

template <Color color>
bool King<color>::is_legal_move(Move &m, BoardBitboard &board) {
  SquareIndices from = Move_Utils::get_from(m);
  U64 to = ONE << Move_Utils::get_to(m);
  U64 free_squares = ~board[BOTH];
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (Move_Utils::can_castle(m))
    return eheck_legal_castle(m, board);

  if (captured) 
    free_squares |= board[utils::check::get_color_piece(captured)];

  return m_attacks[from] & to & free_squares;
}

template <Color color>
bool King<color>::eheck_legal_castle(const Move& m, BoardBitboard &b) {
  const SquareIndices from = Move_Utils::get_from(m);
  const SquareIndices to = Move_Utils::get_to(m);
  const KingCastle &kc  = m_kc.at(Move_Utils::get_castle_permission(m));

  if (from != static_cast<SquareIndices>(kc._from)) return false;
  if (to != static_cast<SquareIndices>(kc._to))  return false;

  for (const auto pos : kc.free_squares)
    if (b.is_occupied_at_pos(pos)) return false;

  return true;
}

