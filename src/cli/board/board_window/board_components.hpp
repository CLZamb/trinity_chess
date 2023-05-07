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
using BCI = BoardConfigInfo;

inline auto new_info_check_behaviour(BoardCheck &b,
                                     shared_ptr<BoardModelInfo> m) {
  return make_unique<BoardCheckInfoDecorator>(std::move(b.get_behaviour()), m);
}

inline auto new_model_info() { return std::make_shared<BoardModelInfo>(); }

inline auto new_info_pane(BoardCheck &board_check) {
  auto mi = new_model_info();
  auto ip = make_unique<InfoPane>(mi);

  board_check.set_behaviour(new_info_check_behaviour(board_check, mi));
  return ip;
}

inline auto new_statistics_pane() { return make_unique<StatisticsPane>(); }

inline auto new_board_pane(const std::unique_ptr<KeyboardInput> &keyboard_input,
                           const FenFields &fen,
                           Color initial_side) {
  return make_unique<KeyboardBoardPane>(keyboard_input, fen, initial_side);
}

inline auto new_board_pane(const std::unique_ptr<TextInput> &text_input,
                           const FenFields &fen) {
  return make_unique<TextBoardPane>(text_input, fen);
}

inline auto new_side_pane(BCI::SidePane side_pane_type, BoardCheck &board_check)
    -> std::unique_ptr<IBoardSidePane> {
  switch (side_pane_type) {
    case BCI::Info:
      return new_info_pane(board_check);
    case BCI::Statitics:
      return new_statistics_pane();
    case BCI::None:
      [[fallthrough]];
    default:
      return nullptr;
  }
}
}   // namespace BoardComponents

#endif /* BOARD_COMPONENTS_H */
