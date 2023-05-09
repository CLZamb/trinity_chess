#ifndef BOARD_COMPONENTS_H
#define BOARD_COMPONENTS_H

#include "board/board_window/board_pane/keyboard_board_pane.h"
#include "board/board_window/board_pane/text_board_pane.h"
#include "board/board_window/info_pane/board_check_info.h"
#include "board/board_window/info_pane/info_pane.h"
#include "board/board_window/statistics_pane/statistics_pane.hpp"

namespace BoardComponents {
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;
using BCI = BoardConfigInfo;

inline auto new_board_info_model() {
  return std::make_shared<BoardInfoModel>();
}

inline auto new_info_pane(unique_ptr<IBoardCheck> &board_check) {
  auto mi = new_board_info_model();
  board_check = make_unique<BoardCheckInfo>(std::move(board_check), mi);
  return make_unique<InfoPane>(mi, std::make_unique<InfoView>());
}

// inline auto new_statistics_pane() { return make_unique<StatisticsPane>(); }

inline auto new_board_pane(const std::unique_ptr<KeyboardInput> &keyboard_input,
                           const BoardConfigInfo &b_config) {
  return make_unique<KeyboardBoardPane>(keyboard_input, b_config);
}

inline auto new_board_pane(const std::unique_ptr<TextInput> &text_input,
                           const FenFields &fen) {
  return make_unique<TextBoardPane>(text_input, fen);
}
}   // namespace BoardComponents

#endif /* BOARD_COMPONENTS_H */
