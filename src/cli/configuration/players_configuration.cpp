#include "players_configuration.h"

PlayersConfig::PlayersConfig() {}

PlayersConfig::PlayersConfig(PlayerType t1, PlayerType t2) {
  player[Color::WHITE]  = t1;
  player[Color::BLACK] = t2;
}

PlayerType PlayersConfig::get_type(Color c) {
  return player[c];
}

void PlayersConfig::set_type(Color c, PlayerType t) {
  player[c] = t;
}

