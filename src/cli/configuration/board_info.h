#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <string>
#include "game/game_typedefs.h"
#include "ui_components/fen_fields.hpp"

struct BoardInfo {
  enum SidePane {
    None,
    Info,
    Statitics,
  };
  FenFields start_fen_fields;
  InputType input_type;
  Color initial_side;
  BoardInfo::SidePane left_pane;
  BoardInfo::SidePane right_pane;
};

#endif /* BOARD_INFO_H */
