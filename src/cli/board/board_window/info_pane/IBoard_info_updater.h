#ifndef IBOARD_INFO_UPDATER_H
#define IBOARD_INFO_UPDATER_H

#include "game/game_typedefs.h"
#include "utils/move.hpp"

class IBoardSaveInfo {
 public:
  virtual void save_info(const std::string &info) = 0;
};

#endif /* IBOARD_MODE_INFO_UPDATE_H */
