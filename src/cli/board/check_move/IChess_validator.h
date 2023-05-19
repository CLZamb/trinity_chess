#ifndef IBOARD_CHECK_H
#define IBOARD_CHECK_H

#include "game/turn/game_turn_observer.h"
#include "utils/move.hpp"

class IChessValidator : public GameTurnObserver {
public:
  virtual ~IChessValidator() = default;
  virtual void update_turn(const Color &) = 0;
  virtual bool is_player_in_check(const Move&m) = 0;
  virtual bool is_string_move_format_valid(const std::string& s) = 0;
  virtual bool is_legal_move(Move &) = 0;
  virtual bool is_checkmate() = 0;
};

#endif /* BOARD_CHECK_H */
