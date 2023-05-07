#include "board.h"

#include "board/board_window/board_components.hpp"
#include "board/board_window/board_window.h"
#include "input/input_components.h"
#include "utils/move.hpp"

Board::Board(BoardInfo &b)
    : m_side_to_move(b.initial_side)
    , m_position_fen(b.start_fen_fields, m_position)
    , m_special_move(m_position)
    , m_board_check(m_position) {
  build_window(b);
  m_side_to_move.attach(&m_board_check);
  m_side_to_move.attach(&m_position);
  m_side_to_move.notify_side();
}

Board::~Board() {}

void Board::build_window(BoardInfo &b_info) {
  // auto input = InputComponents::new_input_text(" >> ");
  auto input = InputComponents::new_input_keyboard();
  auto board_pane = BoardComponents::new_board_pane(input, b_info.start_fen_fields,
                                                    m_side_to_move.get_color());
  auto left_pane =
      BoardComponents::new_side_pane(b_info.left_pane, m_board_check);
  auto right_pane =
      BoardComponents::new_side_pane(b_info.right_pane, m_board_check);

  m_board_window.set_input(std::move(input));
  m_board_window.set_board_pane(std::move(board_pane), Window::Middle_pane);

  if (left_pane) {
    m_board_window.set_side_pane(std::move(left_pane), Window::Left_pane);
  }

  if (right_pane) {
    m_board_window.set_side_pane(std::move(right_pane), Window::Right_pane);
  }
}

Color Board::get_winner_side() { return m_side_to_move.get_color(); }

void Board::change_side() { m_side_to_move.change_side(); }

void Board::print() {
  m_board_window.update();
  m_board_window.print();
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
