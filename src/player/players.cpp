#include "headers/players.h"

Players::Players() : m_turn(&players_info[GameTurn::player_1]) {}
Players::Players(PlayersConfig& config) : Players() {
  create_players(config);
}

Players::~Players() {}

void Players::create_players(PlayersConfig& config) {
  players_info[GameTurn::player_1] = config.get_player_info(GameTurn::player_1);
  players_info[GameTurn::player_2] = config.get_player_info(GameTurn::player_2);

  players[GameTurn::player_1] = create_new_player(players_info[GameTurn::player_1]);
  players[GameTurn::player_2] = create_new_player(players_info[GameTurn::player_2]);
}

std::unique_ptr<Player>
Players::create_new_player(PlayerInfo &p) {
  if (p.get_type() == PlayerInfo::Human) 
    return std::make_unique<Player>(Player(p.get_color()));

  // else Playyer::CPU
  return std::make_unique<Player>(Player(p.get_color()));
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

std::shared_ptr<Player> Players::get_player_turn() {
  return p_game_turn;
}
