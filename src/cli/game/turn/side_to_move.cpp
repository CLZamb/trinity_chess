#include "side_to_move.h"
#include <iostream>

SideToMove::SideToMove(PlayersConfig &config) {
  create_players_info(config);
  set_inital_side(config.get_initial_color());
}

void SideToMove::create_players_info(PlayersConfig &config) {
  players_info[Color::WHITE] = config.get_player_info(Color::WHITE);
  players_info[Color::BLACK] = config.get_player_info(Color::BLACK);
}

SideToMove::~SideToMove() {}

void SideToMove::set_new_configuration(PlayersConfig& c) {
  create_players_info(c);
  set_inital_side(c.get_initial_color());
  notify_turn();
}

void SideToMove::change_turn() {
  m_turn = 
    m_turn == Color::WHITE ? 
      Color::BLACK : Color::WHITE;

  notify_turn();
}

void SideToMove::notify_turn() {
  for (auto observer : *_observers)
    observer->update_turn(players_info[m_turn]);
}

void SideToMove::set_inital_side(const Color &c) {
  m_turn = c;
}

Color SideToMove::get_turn_color() {
  return m_turn;
}
