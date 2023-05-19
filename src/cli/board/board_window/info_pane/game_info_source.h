#ifndef GAME_INFO_SOURCE_H
#define GAME_INFO_SOURCE_H

#include <memory>
#include "board/board_window/info_pane/IBoard_info_updater.h"

class GameInfoSource {
 public:
  virtual void set_board_info(std::shared_ptr<IBoardSaveInfo> board_save_info) = 0;
};

#endif /* GAME_INFO_SOURCE_H */
