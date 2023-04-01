#ifndef PLAYERS_TURN_CONTROLLER_H
#define PLAYERS_TURN_CONTROLLER_H

#include "players_configuration.h"
#include "game_turn_observable.h"

using std::array;

class PlayersTurnController : public GameTurnObservable {
public:
  PlayersTurnController(PlayersConfig &config);
  virtual ~PlayersTurnController();
  void create_players(PlayersConfig &config);
  void notify_change_turn();
  void change_turn();
  void set_inital_side(const GameTurn::Players &p);
  GameTurn::Players get_turn();

private:
  static const int players_size = GameTurn::kSize;
  array<PlayerInfo, players_size> players_info;
  GameTurn::Players m_turn;
};

#endif /* PLAYERS_TURN_CONTROLLER_H */
