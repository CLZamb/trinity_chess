#include "board.h"

#include "board/board_window/board_components.hpp"
#include "input/input_components.h"
#include "utils/move.hpp"

namespace MU = MoveUtils;
namespace SU = StringUtils;
namespace IC = InputComponents;
namespace BC = BoardComponents;

using std::make_unique;
using std::string;
using W = Window::PanePos;

Board::Board(BoardConfigInfo &c)
    : m_chess(c)
    , m_window(c) {
  m_window.add_side_pane(BC::new_side_pane(m_chess, c.left_pane), W::LEFT_PANE);
  m_window.add_side_pane(BC::new_side_pane(m_chess, c.right_pane),
                         W::RIGHT_PANE);
}

void Board::make_move(const Move &mv) {
  m_chess.make_move(mv);
  m_window.make_move(mv);
}

bool Board::is_invalid_move(const Move &mv) { return mv == MU::INVALID_MOVE; }

Move Board::get_player_move() {
  Move mv{MU::INVALID_MOVE};

  std::string move_str = get_string_move();

  mv = m_chess.convert_string_to_move(move_str);

  if (m_chess.is_player_in_check(mv) || !m_chess.is_legal_move(mv)) {
    return MU::INVALID_MOVE;
  }

  return mv;
}

std::string Board::get_string_move() {
  string move_str;

  do {
    move_str = m_window.get_move_as_string();
  } while (!m_chess.is_string_move_format_valid(move_str));

  return move_str;
}

void Board::print() { m_window.print(); }

Color Board::get_winner_side() { return m_chess.get_cur_color_side(); }

void Board::change_side() { m_chess.change_side(); }

bool Board::is_checkmate() { return m_chess.is_checkmate(); }
