#include "board.h"

#include "board/board_window/board_components.hpp"
#include "configuration/input_configuration.hpp"
#include "utils/move.hpp"

Board::Board(BoardConfig &bc)
    : m_side_to_move(bc.get_initial_color())
    , m_special_move(m_position)
    , m_board_check(m_position)
    , m_board_window(bc.get_fen(), bc.get_input_type(), m_side_to_move) {
  m_side_to_move.attach(&m_board_check);
  m_side_to_move.attach(&m_position);
  m_side_to_move.notify_side();

  m_position_fen.parse_fen(bc.get_fen(), m_position);
  add_info_pane();
}

Board::~Board() {}

void Board::add_info_pane() { m_board_window.add_info_pane(m_board_check); }

Color Board::get_winner_side() { return m_side_to_move.get_color(); }

void Board::change_side() { m_side_to_move.change_side(); }

void Board::print() {
  m_board_window.update();
  m_board_window.print();
}

void Board::parse_fen(const string &fen) {
  m_board_window.parse_fen(fen);
  m_position_fen.parse_fen(fen, m_position);
}

Move Board::get_player_move() {
  Move mv{MoveUtils::INVALID_MOVE};
  string s_move = m_board_window.get_player_move_as_string();

  if (!m_board_check.is_string_move_format_valid(s_move)) {
    return MoveUtils::INVALID_MOVE;
  }

  mv = convert_string_to_move(s_move);

  if (m_board_check.is_player_in_check(mv) ||
      !m_board_check.is_legal_move(mv)) {
    return MoveUtils::INVALID_MOVE;
  }

  return mv;
}

bool Board::is_invalid_move(const Move &mv) {
  return mv == MoveUtils::INVALID_MOVE;
}

void Board::make_move(const Move &mv) {
  m_position.make_move(mv);
  m_board_window.make_move(mv);

  m_special_move.handle_special_move(mv, m_position);
  std::cout << m_position_fen.get_fen(m_position) << std::endl;
}

Move Board::convert_string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  Square from = MoveUtils::get_from(mv);
  Square to = MoveUtils::get_to(mv);

  Piece piece_taken = m_position.get_piece_at_square(from);
  Piece piece_captured = m_position.get_piece_at_square(to);

  MoveUtils::set_piece(mv, piece_taken);
  MoveUtils::set_capture_piece(mv, piece_captured);

  m_special_move.set_special_move(mv, m_position);
  return mv;
}

bool Board::is_checkmate() { return m_board_check.is_checkmate(); }
