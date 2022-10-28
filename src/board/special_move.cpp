#include "headers/special_move.h"

SpecialMove::SpecialMove() {}
SpecialMove::~SpecialMove() {}

void SpecialMove::capture_en_passant(const Move& mv, Squares& squares) {
  Direction d = (utils::check::is_black_piece(Move_Utils::get_piece(mv)) ?  NORTH :  SOUTH);
  SquareIndices piece_capture_position = Move_Utils::get_to(mv) + d;
  squares[piece_capture_position].clear_square();
}

void SpecialMove::move_rook(const Move &m, Squares &s) {
  const Move r_pos =  m_castling.get_rook_castle_move(Move_Utils::get_castle_permission(m));
  SquareIndices from_pos = Move_Utils::get_from(r_pos);
  SquareIndices to_pos = Move_Utils::get_to(r_pos);
  s.do_move(from_pos, to_pos);
}

bool SpecialMove::is_first_move(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  if (piece == bP) {
    if (Pawn<BLACK>::is_first_move(m))
      return true;
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_first_move(m))
      return true;
  }

  return false;
}

bool SpecialMove::is_double_forward_move(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  if (piece == bP) {
    if (Pawn<BLACK>::is_double_forward_move(m))
      return true;
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_double_forward_move(m))
      return true;
  }
  return false;
}


void SpecialMove::set_castle_permission(CastlePermission perm) {
  m_castling.set_castle_permission(perm);
}

const SquareIndices &SpecialMove::get_en_passant_square() {
  return m_en_passant.get_en_passant_position();
}

void SpecialMove::set_en_passant_square(SquareIndices sq) {
  m_en_passant.set_en_passant_position(sq);
}

void SpecialMove::handle_special_move(const Move& m, Squares& squares) {
  switch (m_type) {
    case SpecialMove::Pawn_Promotion:
      break;
    case SpecialMove::En_Passant:
      capture_en_passant(m, squares);
      break;
    case SpecialMove::Castling_Move:
      move_rook(m, squares);
      break;
    case SpecialMove::None:
    default:
      break;
  }
}

bool SpecialMove::is_special_move(const Move& m) {
  if (Move_Utils::is_en_passand(m)) return true;
  if (Move_Utils::get_castle_permission(m) != NO_CASTLING) return true;
  if (Move_Utils::get_promoted_piece(m) != EMPTY)  return true;
  return false;
}

void SpecialMove::set_special_move_to_move(Move& m, Squares &squares) {
  if (m_castling.is_castle_move(m, squares)) {
    m_castling.assign_castle_rights_to_move(m);
    m_type = Castling_Move;

  } else if (m_en_passant.is_en_passant_move(m)) {
    m_en_passant.set_en_passant_to_move(m);
    m_type = En_Passant;

  } // else if (m_pawn_promotion) {
  // }
}
