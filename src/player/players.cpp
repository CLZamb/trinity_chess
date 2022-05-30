#include "headers/players.h"

Players::Players() : m_turn(&p1) {}
Players::Players(PlayersConfig& config) : Players() {
  create_players(config);
}

Players::~Players() {}

void Players::create_players(PlayersConfig& config) {
  p1 = config.get_player_info(GameTurn::player_1);
  p2 = config.get_player_info(GameTurn::player_2);

  players[GameTurn::player_1] = create_new_player(config.get_type(GameTurn::player_1), config.get_color(GameTurn::player_1));
  players[GameTurn::player_2] = create_new_player(config.get_type(GameTurn::player_2), config.get_color(GameTurn::player_2));

  players[GameTurn::player_1]->set_opponent(players[GameTurn::player_2]);
  players[GameTurn::player_2]->set_opponent(players[GameTurn::player_1]);
}

std::shared_ptr<Player> Players::get_player(GameTurn::players gt) { 
  return players[gt]; 
}

std::unique_ptr<Player>
Players::create_new_player(PlayerInfo::Type type, Color color) {
  if (type == PlayerInfo::Human) 
    return std::make_unique<Player>(Player(color));

  // else Playyer::CPU
  return std::make_unique<Player>(Player(color));
}

void Players::change_turn() {
  m_turn = m_turn->get_turn() == GameTurn::player_1 ? &p2 : &p1;
  notify();
}

void Players::notify() {
  for (auto observer : *_observers) {
    observer->update_turn(*m_turn);
  }
}

std::shared_ptr<Player> Players::get_player_turn() {
  return p_game_turn;
}

void Players::set_inital_side(GameTurn::players gt) {
  m_turn = (gt == GameTurn::player_1) ? &p1 : &p2;
}
