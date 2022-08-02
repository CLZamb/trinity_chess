#include "headers/board.h"

Board::Board(string fen /*"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"*/) : 
  m_fen(m_squares) {
  m_fen.parse_fen(fen, m_board_bitboard);
}

bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) { m_turn_info = turn; }

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
  SquareIndices from = SquareEnd;
  SquareIndices to = SquareEnd;
  from = Move_Utils::get_from(mv);
  to = Move_Utils::get_to(mv);

  m_squares.do_move(from, to);

  if (Move_Utils::can_castle(mv)) {
    CastlePermission caslte_perm = Move_Utils::get_castle_permission(mv);
    move_castle_move(m_castling.get_rook_castle_move(caslte_perm));
  }
}

Move Board::string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  Piecetype piece = m_squares[from].get_piece();
  Piecetype captured = m_squares[to].get_piece();

  Move_Utils::set_piece(mv, piece);
  Move_Utils::set_capture_piece(mv, captured);

  if (can_castle() && is_castle_move(mv))
    m_castling.assign_castle_rights_to_move(mv, m_turn_info.color);

  return mv;
}

bool Board::can_castle() {
  return m_board_bitboard.get_castle_permission() != NO_CASTLING;
}

bool Board::is_castle_move(const Move& m) {
  bool is_castle_move = m_castling.is_castle_move(m, m_turn_info.color);
  CastleSquares rook_initial_pos = m_castling.get_castle_rook_initial_position(m, m_turn_info.color);
  Piecetype piece_at_rook_initial_pos = m_squares[rook_initial_pos].get_piece();
  return is_castle_move & (piece_at_rook_initial_pos == bR || piece_at_rook_initial_pos == wR);
}

// bool Board::is_en_passant_move(Move& m) {
// }
//

void Board::move_castle_move(const std::pair<CastleSquares, CastleSquares>& r_pos) {
  SquareIndices from_pos = static_cast<SquareIndices>(r_pos.first);
  SquareIndices to_pos = static_cast<SquareIndices>(r_pos.second);
  m_squares.do_move(from_pos, to_pos);
}

BoardFen &Board::get_board_fen() { return m_fen; }
