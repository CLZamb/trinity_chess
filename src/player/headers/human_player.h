#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"
#include "view/headers/board_view.h"

class HumanPlayer : public Player {
public:
  HumanPlayer();

  const string &get_player_string_move() const override;
  void set_from_poistion(const int &pos) { from_pos = pos; }
  void set_to_position(const int &pos) { to_pos = pos; }

  const int &get_from_position() const { return from_pos; }
  const int &get_to_position() const { return to_pos; }

private:
  string m_string_player_input = "error";
  int from_pos{E4};
  int to_pos{E4};
};

#endif /* HUMAN_PLAYER_H */
