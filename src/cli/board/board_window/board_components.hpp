#ifndef BOARD_COMPONENTS_H
#define BOARD_COMPONENTS_H

#include <memory>

#include "board/board_window/board_pane/board_pane.h"
#include "board/board_window/info_pane/board_check_info.h"
#include "board/board_window/info_pane/board_info_model.h"
#include "board/board_window/info_pane/info_pane.h"
#include "board/board_window/info_pane/info_view.h"
#include "board/board_window/statistics_pane/statistics_pane.hpp"
#include "board/chess/chess.h"
#include "board/chess/position/position.h"
#include "input/input_components.h"

namespace BoardComponents {
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;
using BCI = BoardConfigInfo;

inline auto new_board_info_model() {
  return std::make_shared<BoardInfoModel>();
}

inline auto new_info_view() { return make_unique<InfoView>(); }

inline auto new_statistics_pane(Chess &) {
  return make_unique<StatisticsPane>();
}

inline auto new_board_pane(const BoardConfigInfo &b_info) {
  return make_shared<BoardPane>(b_info);
}

inline auto add_info_to_validator(std::unique_ptr<IChessValidator> &&check) {
  return make_unique<BoardCheckInfo>(std::move(check));
}

inline auto new_info_pane(Chess &chess) { return make_shared<InfoPane>(chess); }

inline auto new_side_pane(Chess &chess, const SidePaneType &side_pane)
    -> shared_ptr<IBoardPaneComponent> {
  switch (side_pane) {
    case SidePaneType::Info:
      return new_info_pane(chess);
    case SidePaneType::Statitics:
      return new_statistics_pane(chess);
    default:
      return nullptr;
  }
}

inline auto new_keyboard_event_handler(Color intial_side,
                                       BoardPaneView &squares_drawing) {
  return std::make_unique<KeyboardEventHandler>(intial_side, squares_drawing);
}

inline auto new_text_event_handler() {
  return std::make_unique<TextEventHandler>();
}

}   // namespace BoardComponents

#endif /* BOARD_COMPONENTS_H */
