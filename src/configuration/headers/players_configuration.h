#ifndef PLAYER_CONFIG_H
#define PLAYER_CONFIG_H

#include "game/headers/game_turn.h"
#include "model/headers/player_info.h"
#include <array>

using std::array;

class PlayersConfig {
public:
  PlayersConfig();
  PlayersConfig(GameTurn::Type, GameTurn::Type);

  void set_color(GameTurn::Players, Color c);
  Color get_color(GameTurn::Players p);

  void  set_type(GameTurn::Players, GameTurn::Type c);
  GameTurn::Type get_type(GameTurn::Players p);

  PlayerInfo get_player_info(GameTurn::Players);

private:
  array<PlayerInfo, GameTurn::kSize> player {{
    {WHITE, GameTurn::Human, GameTurn::player_1},
    {BLACK, GameTurn::Human, GameTurn::player_2}
  }};
};
#endif /* PLAYER_CONFIG_H */