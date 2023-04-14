#include "players_configuration.h"

PlayersConfig::PlayersConfig() {}
PlayersConfig::PlayersConfig(PlayerType t1, PlayerType t2) {
  player[Color::WHITE].type = t1;
  player[Color::BLACK].type = t2;
}

void PlayersConfig::set_initial_color(Color c) {
  m_initial_side = c;
}

Color PlayersConfig::get_initial_color() {
  return m_initial_side;
}

PlayerType PlayersConfig::get_type(Color c) {
  return player[c].type;
}

void PlayersConfig::set_type(Color c, PlayerType t) {
  player[c].type = t;
}

PlayerInfo PlayersConfig::get_player_info(Color c) {
  return player[c];
}
