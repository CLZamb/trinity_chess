#include "headers/board.h"

Board::Board(string fen /*"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"*/) : 
  m_fen(m_squares) {
  m_fen.parse_fen(fen, m_board_state);
}

bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) { m_turn_info = turn; }

bool Board::is_legal_move(Move &m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);
  bool is_black_piece = utils::check::is_black_piece(piece);
  bool is_black_captured = utils::check::is_black_piece(captured);
 
  if (!piece || !check_piece_belongs_to_player(is_black_piece))
    return false;

  // if (!is_special_move(m)) return false;

  if (captured && check_piece_belongs_to_opponent(is_black_captured)) {
    return m_pieces[piece]->is_legal_attack_move(m, m_board_state);
  }

  return m_pieces[piece]->is_legal_non_attack_move(m, m_board_state);
}

bool Board::check_piece_belongs_to_opponent(const bool is_black_piece) {
  return !check_piece_belongs_to_player(is_black_piece);
}

bool Board::check_piece_belongs_to_player(const bool is_black_piece) {
  return is_black_piece == m_turn_info.color;
}

void Board::make_move(Move mv) {
  m_board_state.move(mv);
  move_piece_to_square(mv);
}

Move Board::string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  Piecetype piece = m_squares[from].get_piece();
  Piecetype captured = m_squares[to].get_piece();

  Move_Utils::set_piece(mv, piece);
  Move_Utils::set_capture_piece(mv, captured);
  return mv;
}

void Board::move_piece_to_square(const Move &mv) {
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  m_squares[to].set_piece(m_squares[from].get_piece());
  m_squares[from].clear_square();
}

BoardFen &Board::get_board_fen() { return m_fen; }
