#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <string>

#include "game/game_typedefs.h"
#include "ui_components/fen_fields.hpp"
#include "ui_components/window.h"

enum class SidePaneType {
  None,
  Info,
  Statitics,
};

struct BoardSidePaneInfo {
  SidePaneType type;
  Window::PanePos pos;
};

struct BoardConfigInfo {
  FenFields fen_fields;
  InputType input_type;
  Color initial_side;
  BoardSidePaneInfo left_pane{SidePaneType::None, Window::LEFT_PANE};
  BoardSidePaneInfo right_pane{SidePaneType::None, Window::RIGHT_PANE};
};

#endif /* BOARD_INFO_H */
