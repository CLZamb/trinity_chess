#include "castling.h"

const unordered_map<CastlePermission, const Move> Castling::m_rook_castle_pos { 
  {NO_CASTLING, 0},
  {WKCA , m_wkca},
  {WQCA , m_wqca},
  {BKCA , m_bkca},
  {BQCA , m_bqca},
};

const unordered_map<CastleSquares, CastlePermission> Castling::m_white_permission {
  {WK_CA_KING_SIDE_END_POS, WKCA},
  {WK_CA_QUEEN_SIDE_END_POS, WQCA},
};

const unordered_map<CastleSquares, CastlePermission> Castling::m_black_permission {
  {BK_CA_KING_SIDE_END_POS, BKCA},
  {BK_CA_QUEEN_SIDE_END_POS, BQCA},
};

const unordered_map<Color, const unordered_map<CastleSquares, CastlePermission>> Castling::m_castle_permission {
  {WHITE, m_white_permission},
  {BLACK, m_black_permission},
};

Castling::Castling() {}

const Move& Castling::get_rook_castle_move(const CastlePermission &cp) const {
  return m_rook_castle_pos.at(cp);
}

bool Castling::is_rook_is_at_castling_position(const Move& m, Squares &s) {
  Color color = utils::check::get_color_piece(Move_Utils::get_piece(m));
  CastleSquares rook_initial_pos = get_castle_rook_initial_position(m, color);
  Piecetype piece_at_rook_initial_pos = s[static_cast<size_t>(rook_initial_pos)].get_piece();
  return (piece_at_rook_initial_pos == bR || piece_at_rook_initial_pos == wR);
}

bool Castling::is_castle_move(const Move& m, Squares &squares) {
  if (get_castle_permission() ==  NO_CASTLING) return false;
  if (!is_rook_is_at_castling_position(m, squares)) return false;

  Color side = utils::check::get_color_piece(Move_Utils::get_piece(m));
  Piecetype piece = Move_Utils::get_piece(m);
  unsigned int from = Move_Utils::get_from(m);
  unsigned int to = Move_Utils::get_to(m);

  if (side == WHITE) {
    if (piece != wK || from != WK_CA_INITIAL_POS) 
      return false;

    if (to == WK_CA_KING_SIDE_END_POS || to == WK_CA_QUEEN_SIDE_END_POS)
      return true;

  } else if (side == BLACK) {
    if (piece != bK || from != BK_CA_INITIAL_POS) 
      return false;

    if (to == BK_CA_KING_SIDE_END_POS || to == BK_CA_QUEEN_SIDE_END_POS)
      return true;
  }

  return false;
}

CastleSquares Castling::get_castle_rook_initial_position(const Move& m, const Color &side) {
  unsigned int to = Move_Utils::get_to(m);

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

void Castling::set_castle_permission(CastlePermission c) {
  castle_perm |= c;
}

const int &Castling::get_castle_permission() {
  return castle_perm;
}

void Castling::move_rook(const Move &m, Squares &s) {
  const CastlePermission perm = Move_Utils::get_castle_permission(m);
  const Move r_pos =  get_rook_castle_move(perm);
  s.do_move(r_pos);
  remove_castle_permission(perm);
}

void Castling::assign_special_to_move(Move& m) {
  Color side = utils::check::get_color_piece(Move_Utils::get_piece(m));
  CastleSquares to = static_cast<CastleSquares>(Move_Utils::get_to(m));
  Move_Utils::set_castle_permission(m, m_castle_permission.at(side).at(to));
}

void Castling::handle_special_move(const Move& m, Squares &s) {
  move_rook(m, s);
}

void Castling::remove_castle_permission(const CastlePermission& perm) {
  castle_perm ^= perm;
}
