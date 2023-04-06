#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#include "utils/utilities.h"

struct PlayerInfo {
  Color color {NONE};
  PlayerType type {PlayerType::Human};
};

#endif /* PLAYER_INFO_H */

