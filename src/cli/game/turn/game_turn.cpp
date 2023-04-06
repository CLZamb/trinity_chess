#include "game_turn.h"
#include <iostream>

GameTurn::GameTurn(PlayersConfig &config) {
  create_players_info(config);
  set_inital_side(config.get_initial_color());
}

void GameTurn::create_players_info(PlayersConfig &config) {
  players_info[Color::WHITE] = config.get_player_info(Color::WHITE);
  players_info[Color::BLACK] = config.get_player_info(Color::BLACK);
}

GameTurn::~GameTurn() {}

void GameTurn::set_new_configuration(PlayersConfig& c) {
  create_players_info(c);
  set_inital_side(c.get_initial_color());
  notify_game_turn();
}
void GameTurn::change_turn() {
  m_turn = 
    m_turn == Color::WHITE ? 
      Color::BLACK : Color::WHITE;

  notify_game_turn();
}

void GameTurn::notify_game_turn() {
  for (auto observer : *_observers)
    observer->update_turn(players_info[m_turn]);
}

void GameTurn::set_inital_side(const Color &c) {
  m_turn = c;
}

Color GameTurn::get_turn_color() {
  return m_turn;
}
