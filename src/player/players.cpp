#include "headers/players.h"

Players::Players(PlayersConfig &config)
    : m_turn(&players_info[GameTurn::player_1]) {
  create_players(config);
}

Players::~Players() {}

void Players::create_players(PlayersConfig& config) {
  players_info[GameTurn::player_1] = config.get_player_info(GameTurn::player_1);
  players_info[GameTurn::player_2] = config.get_player_info(GameTurn::player_2);
}

void Players::change_turn() {
  m_turn = &players_info
  [
    m_turn->turn == GameTurn::player_1 ? 
    GameTurn::player_2 : 
    GameTurn::player_1
  ];
  notify_change_turn();
}

void Players::notify_change_turn() {
  for (auto observer : *_observers) {
    observer->update_turn(*m_turn);
  }
}

void Players::set_inital_side(GameTurn::Players gt) {
  m_turn = &players_info[gt];
}
