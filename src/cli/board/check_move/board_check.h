#ifndef BOARD_CHECK_H
#define BOARD_CHECK_H

#include "board/board_representation/board.h"
#include "board/check_move/IBoard_check_behaviour.h"
#include "game/turn/game_turn_observer.h"
#include <memory>

class BoardCheck : public GameTurnObserver {
public:
  BoardCheck(Board &b);

  void update_turn(const PlayerInfo &turn) override;
  bool is_checkmate();

  bool is_in_check(const Move &m);
  bool is_string_format_valid(const string &s);
  bool is_legal_move(Move &);
  void set_behaviour(std::unique_ptr<IBoardCheckBehaviour> &&t);
  std::unique_ptr<IBoardCheckBehaviour> &&get_behaviour();

private:
  PlayerInfo m_turn_info;
  std::unique_ptr<IBoardCheckBehaviour> p_behaviour;
};

#endif /* BOARD_CHECK_H */
