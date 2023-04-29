#ifndef BOARD_COMPONENTS_H
#define BOARD_COMPONENTS_H

#include <memory>

#include "board/board_window/board_pane/board_pane.h"
#include "board/board_window/info_pane/board_check_info_decorator.h"
#include "board/board_window/info_pane/info_pane.h"
#include "board/board_window/statistics_pane/statistics_pane.hpp"
#include "board/event_handlers/board_keyboard_event_handler.h"
#include "board/event_handlers/board_text_event_handler.h"
#include "game/turn/side_to_move.h"

namespace BoardComponents {

using std::make_shared;
using std::make_unique;

inline auto new_keyboard_handler(BoardPane &b, const std::unique_ptr<InputEvent>& p,
                                 SideToMove &m_turn) {
  auto k_event_handler = make_shared<BoardKeyboardEventHandler>(b, p);
  m_turn.attach(k_event_handler.get());
  return k_event_handler;
}

inline auto new_text_handler(BoardPane &b, const std::unique_ptr<InputEvent>& p) {
  return make_shared<BoardTextEventHandler>(b, p);
}

inline auto new_info_check_behaviour(BoardCheck &b,
                                     shared_ptr<BoardModelInfo> m) {
  return make_unique<BoardCheckInfoDecorator>(std::move(b.get_behaviour()), m);
}

inline auto new_board_model_info() {
  return std::make_shared<BoardModelInfo>();
}

inline auto new_info_pane(BoardCheck &board_check) {
  auto board_model_info = new_board_model_info();
  auto info_pane = make_shared<InfoPane>(board_model_info);

  board_check.set_behaviour(
      new_info_check_behaviour(board_check, board_model_info));
  return info_pane;
}

inline auto new_statistics_pane() { return make_shared<StatisticsPane>(); }

}   // namespace BoardComponents

#endif /* BOARD_COMPONENTS_H */
