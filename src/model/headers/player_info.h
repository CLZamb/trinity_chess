#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#include "board/headers/utils.h"
#include "game/headers/game_turn.h"

struct PlayerInfo {
  Color color {NONE};
  GameTurn::Type type {GameTurn::Human};
  GameTurn::Players turn {GameTurn::player_1};
};

#endif /* PLAYER_INFO_H */

