#include "players_turn_controller.h"

PlayersTurnController::PlayersTurnController(PlayersConfig &config) : m_turn(GameTurn::player_1) {
  create_players(config);
}

PlayersTurnController::~PlayersTurnController() {}

void PlayersTurnController::create_players(PlayersConfig &config) {
  players_info[GameTurn::player_1] = config.get_player_info(GameTurn::player_1);
  players_info[GameTurn::player_2] = config.get_player_info(GameTurn::player_2);
}

void PlayersTurnController::change_turn() {
  m_turn = m_turn == 
    GameTurn::player_1 ? 
      GameTurn::player_2: 
      GameTurn::player_1;

  notify_change_turn();
}

void PlayersTurnController::notify_change_turn() {
  for (auto observer : *_observers)
    observer->update_turn(players_info[m_turn]);
}

void PlayersTurnController::set_inital_side(const GameTurn::Players &gt) {
  m_turn = gt;
  notify_change_turn();
}

GameTurn::Players PlayersTurnController::get_turn() {
  return m_turn;
}
