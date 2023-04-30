#ifndef BOARD_CHECK_H
#define BOARD_CHECK_H

#include <memory>

#include "board/check_move/IBoard_check_behaviour.h"
#include "board/position/position.h"
#include "game/turn/game_turn_observer.h"

class BoardCheck : public GameTurnObserver {
 public:
  explicit BoardCheck(Position &b);

  void update_turn(const Color &turn) override;
  bool is_checkmate();

  bool is_player_in_check(const Move &m);
  bool is_string_move_format_valid(const std::string &s);
  bool is_legal_move(Move &);
  void set_behaviour(std::unique_ptr<IBoardCheckBehaviour> &&t);
  std::unique_ptr<IBoardCheckBehaviour> &&get_behaviour();

 private:
  Color m_side;
  std::unique_ptr<IBoardCheckBehaviour> p_behaviour;
};

#endif /* BOARD_CHECK_H */
