#include "headers/players.h"

Players::Players(PlayersConfig &config, Input& input)
    : m_turn(&players_info[GameTurn::player_1]),
      m_input(input) {
  create_players(config);
  attach(&m_input);
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
  notify_change_turn();
}

void Players::notify_change_turn() {
  for (auto observer : *_observers) {
    observer->update_turn(*m_turn);
  }
}

void Players::set_inital_side(GameTurn::players gt) {
  m_turn = &players_info[gt];
}

const string& Players::get_current_player_input() {
  return m_input.get_string_input();
}
