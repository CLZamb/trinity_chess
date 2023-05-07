#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <string>
#include "game/game_typedefs.h"
#include "ui_components/fen_fields.hpp"

struct BoardConfigInfo {
  enum SidePane {
    None,
    Info,
    Statitics,
  };
  FenFields fen_fields;
  InputType input_type;
  Color initial_side;
  SidePane left_pane;
  SidePane right_pane;
};

#endif /* BOARD_INFO_H */
