#ifndef PLAYERS_TURN_CONTROLLER_H
#define PLAYERS_TURN_CONTROLLER_H

#include "configuration/players_configuration.h"
#include "game/turn/game_turn_observable.h"

class SideToMove : public GameTurnObservable {
  public:
  explicit SideToMove(Color &c);
  virtual ~SideToMove();
  void notify_side() override;
  void change_side();
  void set_inital_side(const Color &p);
  Color get_color();

private:
  Color m_side {Color::WHITE};
};

#endif /* PLAYERS_TURN_CONTROLLER_H */
