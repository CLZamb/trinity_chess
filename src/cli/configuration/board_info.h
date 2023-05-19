#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <string>

#include "components/fen_fields.hpp"
#include "game/game_typedefs.h"
#include "components/window.h"

enum class SidePaneType {
  None,
  Info,
  Statitics,
};

struct BoardConfigInfo {
  FenFields fen_fields;
  InputType input_type;
  Color initial_side;
  SidePaneType left_pane{SidePaneType::None};
  SidePaneType right_pane{SidePaneType::None};
};

#endif /* BOARD_INFO_H */
