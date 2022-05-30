#include "headers/players_configuration.h"

PlayersConfig::PlayersConfig(PlayerInfo::Type t1, PlayerInfo::Type t2) {
  player[GameTurn::player_1].set_type(t1);
  player[GameTurn::player_2].set_type(t2);
}

Color PlayersConfig::get_color(GameTurn::players gt) {
  return player[gt].get_color();
}

PlayerInfo::Type PlayersConfig::get_type(GameTurn::players gt) {
  return player[gt].get_type();
}

void PlayersConfig::set_color(GameTurn::players gt, Color c) {
  player[gt].set_color(c);
}

PlayerInfo PlayersConfig::get_player_info(GameTurn::players gt)  {
  return player[gt];
}
