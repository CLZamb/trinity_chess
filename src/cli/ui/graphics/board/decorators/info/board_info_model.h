#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include "game/turn/game_turn_observer.h"
#include "savable.h"

using std::string;

class BoardModelInfo : public Savable, public GameTurnObserver {
public:
  BoardModelInfo();
  virtual ~BoardModelInfo();

  void update_turn(const PlayerInfo &p) override;

  void save_player_info(const PlayerInfo &c) override;
  void save_move(const Move &move) override;
  void save_info(const string &info) override;

  string get_moves(Color c) override;
  string get_captures(Color c) override;
  string get_info() override;
  PlayerInfo get_player_info() override;

private:
  string get_move_string(const Move &m);
  string get_captured_string(const Move &m);
  array<string, Color::SIZE> m_turn_string{"Is white turn", "Is black turn"};
  PlayerInfo m_player_info;
};

#endif /* BOARD_INFO_H */
