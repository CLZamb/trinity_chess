#ifndef PLAYERS_TURN_CONTROLLER_H
#define PLAYERS_TURN_CONTROLLER_H

#include "configuration/players_configuration.h"
#include "game/turn/game_turn_observable.h"

using std::array;

class SideToMove : public GameTurnObservable {
  public:
  SideToMove(PlayersConfig &config);
  virtual ~SideToMove();
  void notify_turn() override;
  void change_turn();
  void set_inital_side(const Color &p);
  Color get_color();
  void set_new_configuration(PlayersConfig &config);

private:
  void create_players_info(PlayersConfig &config);
  static const int players_size = Color::SIZE;
  array<PlayerInfo, players_size> players_info;
  Color m_turn {Color::WHITE};
};

#endif /* PLAYERS_TURN_CONTROLLER_H */
