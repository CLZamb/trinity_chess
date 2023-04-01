#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#include <array>
#include <string>
#include "string_utils.h"
#include "savable.h"
#include "game_turn_observer.h"

using std::string;

class BoardModelInfo : public GameTurnObserver, public Savable {
public:
  BoardModelInfo();
  void update_turn(const PlayerInfo &t) override;

  void save_move(const Move &move) override;
  void save_info(const string &info) override;

  void wrong_format(const string &s);
  void illegal_move(const string &s);
  void in_check(const string& s);

  string get_moves() override;
  string get_captures() override;
  string get_info() override;

private:
  string get_move_string(const Move &m);
  string get_captured_string(const Move &m);

  PlayerInfo m_turn;
  string game_info;
  static const string Kwrong_format;
  static const string Killegal_move;
  static const string Kcheck_move;
  array<string, Color::SIZE> m_turn_string{"Is white turn", "Is black turn"};
};

#endif /* BOARD_INFO_H */
