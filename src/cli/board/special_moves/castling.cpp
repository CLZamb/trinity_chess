#include "castling.h"

const std::unordered_map<CastlePermission, const Move> Castling::m_rook_castle_pos { 
  {NO_CASTLING, 0},
  {WKCA , m_wkca},
  {WQCA , m_wqca},
  {BKCA , m_bkca},
  {BQCA , m_bqca},
};

Castling::Castling() {}
Castling::~Castling() {}

const Move& Castling::get_rook_castle_move(const CastlePermission &cp) const {
  return m_rook_castle_pos.at(cp);
}

bool Castling::is_rook_is_at_castling_position(const Move& m, const Position &s) {
  Color color = utils::check::get_color_piece(MoveUtils::get_piece(m));
  CastleSquares rook_initial_pos = get_castle_rook_initial_position(m, color);
  Piece piece_at_rook_initial_pos = s.get_piece(static_cast<Square>(rook_initial_pos));
  return (piece_at_rook_initial_pos == bR || piece_at_rook_initial_pos == wR);
}

bool Castling::is_castle_move(const Move& m, Position &position) {
  if (position.get_castle_permission() == NO_CASTLING) return false;
  if (!is_rook_is_at_castling_position(m, position)) return false;

  Color side = utils::check::get_color_piece(MoveUtils::get_piece(m));
  Piece piece = MoveUtils::get_piece(m);
  unsigned int from = MoveUtils::get_from(m);
  unsigned int to = MoveUtils::get_to(m);

  if (side == WHITE) {
    if (piece != wK || from != WK_CA_INITIAL_POS) { 
      return false;
}

    if (to == WK_CA_KING_SIDE_END_POS || to == WK_CA_QUEEN_SIDE_END_POS) {
      return true;
}

  } else if (side == BLACK) {
    if (piece != bK || from != BK_CA_INITIAL_POS) { 
      return false;
}

    if (to == BK_CA_KING_SIDE_END_POS || to == BK_CA_QUEEN_SIDE_END_POS) {
      return true;
}
  }

  return false;
}

CastleSquares Castling::get_castle_rook_initial_position(const Move& m, const Color &side) {
  unsigned int to = MoveUtils::get_to(m);

  if (side == WHITE) {
    switch (to) {
      case WK_CA_KING_SIDE_END_POS:
        return ROOK_WHITE_CA_KING_SIDE_FROM_POS;
      case WK_CA_QUEEN_SIDE_END_POS:
        return  ROOK_WHITE_CA_QUEEN_SIDE_FROM_POS;
      default: break;
    }  
  } else if (side == BLACK) {
    switch (to) {
      case BK_CA_KING_SIDE_END_POS:
        return ROOK_BLACK_CA_KING_SIDE_FROM_POS;
      case BK_CA_QUEEN_SIDE_END_POS:
        return ROOK_BLACK_CA_QUEEN_SIDE_FROM_POS;
      default: break;
    }
  }

  return NO_CASTLE_POS;
}

void Castling::move_rook(const Move &m, Position &pos) {
  const CastlePermission perm = MoveUtils::get_castle_permission(m);
  const Move r_pos =  get_rook_castle_move(perm);

  pos.make_move(r_pos);
  pos.remove_castle_permission(perm);
}

