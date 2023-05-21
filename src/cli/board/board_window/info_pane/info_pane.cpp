#include "info_pane.h"

#include "board/board_window/board_components.hpp"
#include "board/board_window/info_pane/board_check_info.h"

namespace BC = BoardComponents;

InfoPane::InfoPane(Chess &m_chess) {
  auto validator = BC::add_info_to_validator(m_chess.get_validator());
  validator->set_info_saver(m_info);

  m_chess.set_validator(std::move(validator));
  m_chess.bind(&InfoPane::make_move, this);
  m_chess.bind(&InfoPane::update_turn, this);
}

void InfoPane::make_move(const Move &mv) {
  m_info.save_move(mv);
  if (MoveUtils::get_captured_piece(mv)) {
    m_info.save_capture(mv);
  }

  Color c = m_info.get_side_to_move_color();
  m_view.update_moves(m_info.get_moves(c), c);
  m_view.update_captures(m_info.get_captures(c), c);
}

void InfoPane::update_turn(const Color &c) { m_info.save_side(c); }

void InfoPane::update() {
  m_view.update_banner(m_info.get_side_to_move_color());
  m_view.update_game_info(m_info.get_info());
}
