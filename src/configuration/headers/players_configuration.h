#ifndef PLAYER_CONFIG_H
#define PLAYER_CONFIG_H

#include "game/headers/game_turn.h"
#include "model/headers/player_info.h"
#include <array>

using std::array;

class PlayersConfig {
public:
  PlayersConfig();
  PlayersConfig(PlayerInfo::Type, PlayerInfo::Type);
  void set_color(GameTurn::players, Color c);
  Color get_color(GameTurn::players p);
  PlayerInfo::Type get_type(GameTurn::players p);
  PlayerInfo get_player_info(GameTurn::players);

private:
  array<PlayerInfo, GameTurn::kSize> player{GameTurn::player_1,
                                            GameTurn::player_2};
};

#endif /* PLAYER_CONFIG_H */
