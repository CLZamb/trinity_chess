#include "headers/players.h"

Players::Players() : m_turn(&players_info[GameTurn::player_1]) {}
Players::Players(PlayersConfig& config) : Players() {
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
    m_turn->get_turn() == GameTurn::player_1 ? 
    GameTurn::player_2 : 
    GameTurn::player_1
  ];
  notify();
}

void Players::notify() {
  for (auto observer : *_observers) {
    observer->update_turn(*m_turn);
  }
}

void Players::set_inital_side(GameTurn::players gt) {
  m_turn = &players_info[gt];
}

