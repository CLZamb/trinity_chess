#include "headers/board.h"
#include "board/headers/defs.h"
#include "board/headers/square.h"
#include "board/headers/utils.h"

Board::Board() {}

bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) { 
  m_turn_info = turn; 
}

bool Board::is_legal_move(Move &m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (!piece || !check_piece_belongs_to_player(piece))
    return false;

  if (captured && is_captured_piece_in_same_side(piece, captured))
    return false;

  // if (is_square_attacked(king)) return false;

  return m_pieces[piece]->is_legal_move(m, m_board_bitboard);
}

bool Board::is_captured_piece_in_same_side(const Piecetype piece, const Piecetype captured) {
  return utils::check::get_color_piece(piece) ==
         utils::check::get_color_piece(captured);
}

bool Board::check_piece_belongs_to_player(const Piecetype pc) {
  return utils::check::get_color_piece(pc) == m_turn_info.color;
}

void Board::make_move(Move mv) {
  m_board_bitboard.move(mv);
  move_piece_to_square(mv);
}

void Board::move_piece_to_square(const Move &mv) {
  SquareIndices from = SquareNull;
  SquareIndices to = SquareNull;
  from = Move_Utils::get_from(mv);
  to = Move_Utils::get_to(mv);
  Piecetype piece = Move_Utils::get_piece(mv);

  m_squares.do_move(from, to);

  if (Move_Utils::can_castle(mv)) {
    CastlePermission caslte_perm = Move_Utils::get_castle_permission(mv);
    move_rook_castle_move(m_special_move.get_rook_castle_move(caslte_perm));
  }

  if (is_pawn_piece(piece)) {
    if (is_first_move(mv) && is_double_forward_move(mv)) {
      m_special_move.set_en_passant_square(get_en_passant_move(mv));
    }
  }

  if (Move_Utils::is_en_passand(mv)) {
    if (utils::check::is_black_piece(Move_Utils::get_piece(mv)))
      m_squares[Move_Utils::get_to(mv) + NORTH].clear_square();
    else
      m_squares[Move_Utils::get_to(mv) + SOUTH].clear_square();
  }
}

bool Board::is_first_move(const Move& m) {
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

bool Board::is_double_forward_move(const Move& m) {
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

bool Board::is_pawn_piece(const Piecetype pct) {
  return pct == bP || pct == wP;
}

Move Board::string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  Piecetype piece = m_squares[from].get_piece();
  Piecetype captured = m_squares[to].get_piece();

  Move_Utils::set_piece(mv, piece);
  Move_Utils::set_capture_piece(mv, captured);
  
  switch (m_special_move.check_special_type(mv, m_squares)) {
    case SpecialMove::Pawn_Promotion:
      break;
    case SpecialMove::En_Passant:
      Move_Utils::set_en_passant(mv, true);
      break;
    case SpecialMove::Castling_Move:
      Move_Utils::set_castle_permission(mv, m_special_move.get_castle_permission());
      break;
    case SpecialMove::None:
    default:
      break;
  }

  return mv;
}

SquareIndices Board::get_en_passant_move(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  SquareIndices to = Move_Utils::get_to(m);

  if (piece == bP)
    return (to += NORTH);
  else if (piece == wP)
      return (to += SOUTH);

  return SquareNull;
}

void Board::move_rook_castle_move(const Move& r_pos) {
  SquareIndices from_pos = Move_Utils::get_from(r_pos);
  SquareIndices to_pos = Move_Utils::get_to(r_pos);
  m_squares.do_move(from_pos, to_pos);
}

void Board::clear() {
  m_squares.clear();
  m_board_bitboard.clear();
}

void Board::set_piece_at_square(const SquareIndices& s, const Piecetype& p) {
  m_squares[s].set_piece(p);
  m_board_bitboard.set_bit_at_player_pieces(utils::check::get_color_piece(p), s);
}

Piecetype Board::get_piece_at_square(const int &pos) {
  return m_squares[pos].get_piece();
}

void Board::set_en_passant_square(SquareIndices sq) {
  m_special_move.set_en_passant_square(sq);
}

const SquareIndices &Board::get_en_passant_square() {
  return m_special_move.get_en_passant_square();
}

void Board::set_castle_permission(CastlePermission perm) {
  m_special_move.set_castle_permission(perm);
}

const int &Board::get_castle_permission() {
  return m_special_move.get_castle_permission();
}
