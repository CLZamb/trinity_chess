#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "input_type.h"
#include "player.h"

class HumanPlayer : public Player {
public:
  HumanPlayer(PlayerInput&, SquareIndices sq);
  virtual ~HumanPlayer();
  const string &get_player_string_move() override;

private:
  void set_initial_pos(SquareIndices sq);
  PlayerInput& m_input;
  string m_string_player_input = "error";
  PlayerPosition m_player_pos;
};

#endif /* HUMAN_PLAYER_H */
