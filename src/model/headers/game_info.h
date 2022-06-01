#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <array>
#include <string>
#include "game/headers/game_turn_observer.h"

using std::string;
using std::array;

class GameInfo : public GameTurnObserver {
public:
  GameInfo ();
  void update_info(const string &info);
  void wrong_format(const string &s);
  void illegal_move(const string &s);
  void update_turn(const PlayerInfo &i) override;

  string &get_info();

private:
  string game_info;
  static const string Kwrong_format;
  static const string Killegal_move;
  array<string, GameTurn::kSize> m_turn_string {
    "Is player 1 turn","Is player 2 turn"
  };
  PlayerInfo m_turn;
};

#endif /* GAME_INFO_H */
