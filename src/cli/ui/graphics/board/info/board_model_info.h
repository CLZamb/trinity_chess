#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include "game/turn/game_turn_observer.h"
#include "savable.h"

using std::string;

class BoardModelInfo : public GameTurnObserver, public Savable {
public:
  BoardModelInfo();
  virtual ~BoardModelInfo();
  void update_turn(const PlayerInfo &t) override;

  void save_move(const Move &move) override;
  void save_info(const string &info) override;

  string get_moves() override;
  string get_captures() override;
  string get_info() override;

private:
  string get_move_string(const Move &m);
  string get_captured_string(const Move &m);

  PlayerInfo m_turn;
  string game_info;
  array<string, Color::SIZE> m_turn_string{"Is white turn", "Is black turn"};
};

#endif /* BOARD_INFO_H */
