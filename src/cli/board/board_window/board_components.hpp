#ifndef BOARD_COMPONENTS_H
#define BOARD_COMPONENTS_H

#include "board/board_window/board_pane/keyboard_board_pane.h"
#include "board/board_window/board_pane/text_board_pane.h"
#include "board/board_window/info_pane/board_check_info_decorator.h"
#include "board/board_window/info_pane/info_pane.h"
#include "board/board_window/statistics_pane/statistics_pane.hpp"
#include "board/check_move/board_check.h"
#include "configuration/board_info.h"

namespace BoardComponents {

using std::make_shared;
using std::make_unique;
using std::shared_ptr;

inline auto new_info_check_behaviour(BoardCheck &b,
                                     shared_ptr<BoardModelInfo> m) {
  return make_unique<BoardCheckInfoDecorator>(std::move(b.get_behaviour()), m);
}

inline auto new_model_info() { return std::make_shared<BoardModelInfo>(); }

inline auto new_info_pane(BoardCheck &board_check) {
  auto model_info = new_model_info();
  auto info_pane = make_unique<InfoPane>(model_info);

  board_check.set_behaviour(new_info_check_behaviour(board_check, model_info));
  return info_pane;
}

inline auto new_statistics_pane() { return make_unique<StatisticsPane>(); }

inline auto new_board_pane(const std::unique_ptr<KeyboardInput> &keyboard_input,
                           const FenFields &fen, Color initial_side) {
  return make_unique<KeyboardBoardPane>(keyboard_input, fen, initial_side);
}

inline auto new_board_pane(const std::unique_ptr<TextInput> &text_input,
                           const FenFields &fen) {
  return make_unique<TextBoardPane>(text_input, fen);
}

inline std::unique_ptr<IBoardSidePane> new_side_pane(
    BoardInfo::SidePane side_pane_type, BoardCheck &board_check) {
  switch (side_pane_type) {
    case BoardInfo::Info:
      return BoardComponents::new_info_pane(board_check);
      break;
    case BoardInfo::Statitics:
      BoardComponents::new_statistics_pane();
      break;
    case BoardInfo::None:
    default:
      return nullptr;
  }
  return nullptr;
}
}   // namespace BoardComponents

#endif /* BOARD_COMPONENTS_H */
