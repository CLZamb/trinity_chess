#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "ui/input/board/board_input.h"
#include "utils/defs.h"
#include "player.h"

class HumanPlayer : public Player {
public:
  HumanPlayer(BoardInput&, SquareIndices sq);
  virtual ~HumanPlayer();
  const string &get_player_string_move() override;

private:
  void set_initial_pos(SquareIndices sq);
  BoardInput& m_input;
  string m_string_player_input = "error";
};

#endif /* HUMAN_PLAYER_H */
