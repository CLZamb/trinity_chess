#include "headers/players_configuration.h"

PlayersConfig::PlayersConfig() {}
PlayersConfig::PlayersConfig(GameTurn::Type t1, GameTurn::Type t2) {
  player[GameTurn::player_1].type = t1;
  player[GameTurn::player_2].type = t2;
}

void PlayersConfig::set_color(GameTurn::Players gt, Color c) {
  player[gt].color = c;
}

Color PlayersConfig::get_color(GameTurn::Players gt) {
  return player[gt].color;
}

GameTurn::Type PlayersConfig::get_type(GameTurn::Players gt) {
  return player[gt].type;
}

void PlayersConfig::set_type(GameTurn::Players gt, GameTurn::Type t) {
  player[gt].type = t;
}

PlayerInfo PlayersConfig::get_player_info(GameTurn::Players gt) {
  return player[gt];
}
