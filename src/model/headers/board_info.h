#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <array>
#include <string>
#include "game/headers/game_turn.h"
#include "board/headers/savable.h"
#include "game/headers/game_turn_observer.h"

using std::string;

class BoardInfo : public GameTurnObserver, public Savable {
 public:
  BoardInfo ();
  void save_move(const string& move) override;
  void save_capture(const string& captures) override;
  void update_turn(const PlayerInfo& t) override;
  string get_moves() override;
  string get_captures() override;

 private:
  PlayerInfo m_turn;
};

#endif /* BOARD_INFO_H */
