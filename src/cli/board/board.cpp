#include "board.h"

#include "board/board_window/board_components.hpp"
#include "board/check_move/board_check.h"
#include "input/input_components.h"
#include "utils/move.hpp"

namespace MU = MoveUtils;
namespace IC = InputComponents;
namespace BC = BoardComponents;
namespace SU = StringUtils;
using std::string;
using std::unique_ptr;
using W = Window;
using std::make_unique;

Board::Board(BoardConfigInfo &b)
    : m_side_to_move(b.initial_side)
    , m_position_fen(b.fen_fields, m_position)
    , m_special_move(m_position)
    , p_check(make_unique<BoardCheck>(m_position)) {
  build_window(b);
  m_side_to_move.attach(p_check.get());
  m_side_to_move.attach(&m_position);
  m_side_to_move.notify_side();
}

void Board::build_window(BoardConfigInfo &board_config) {
  // auto input = IC::new_input_text(" >> ");
  auto input = IC::new_input_keyboard();
  auto b_pane = BC::new_board_pane(input, board_config);

  m_board_win.set_board_pane(std::move(b_pane), W::MIDDLE_PANE);
  m_board_win.set_input(std::move(input));
  build_side_pane(board_config.left_pane);
  build_side_pane(board_config.right_pane);
}

void Board::build_side_pane(const BoardSidePaneInfo &side_pane) {
  switch (side_pane.type) {
    case SidePaneType::Info: {
      auto info_pane = BC::new_info_pane(p_check);
      m_side_to_move.attach(info_pane.get());
      m_board_win.add_pane(std::move(info_pane), side_pane.pos);
      break;
    }
    // case SidePaneType::Statitics:
    //   m_board_win.add_pane(BC::new_statistics_pane(), side_pane.pos);
    //   break;
    default:
      break;
  }
}

Color Board::get_winner_side() { return m_side_to_move.get_color(); }

void Board::change_side() {
  m_side_to_move.change_side();
}

void Board::print() {
  m_board_win.update();
  m_board_win.print();
}

bool Board::is_checkmate() { return p_check->is_checkmate(); }

void Board::make_move(const Move &mv) {
  m_position.make_move(mv);
  m_board_win.make_move(mv);

  m_special_move.handle_special_move(mv, m_position);
}

bool Board::is_invalid_move(const Move &mv) { return mv == MU::INVALID_MOVE; }

Move Board::get_player_move() {
  Move mv{MU::INVALID_MOVE};
  string move_str = m_board_win.get_player_move_as_string();

  if (!p_check->is_string_move_format_valid(move_str)) {
    return MU::INVALID_MOVE;
  }

  mv = convert_string_to_move(move_str);

  if (p_check->is_player_in_check(mv) || !p_check->is_legal_move(mv)) {
    return MU::INVALID_MOVE;
  }

  return mv;
}

Move Board::convert_string_to_move(const string &m) {
  Move mv = SU::to_move(m);
  Square from = MU::get_from(mv);
  Square to = MU::get_to(mv);

  Piece piece_taken = m_position.get_piece(from);
  Piece piece_captured = m_position.get_piece(to);

  MU::set_piece(mv, piece_taken);
  if (piece_captured) { MU::set_capture_piece(mv, piece_captured); }

  m_special_move.set_special_move(mv, m_position);
  return mv;
}
