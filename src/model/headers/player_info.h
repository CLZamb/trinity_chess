#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H
#include "board/headers/utils.h"
#include "game/headers/game_turn.h"

class PlayerInfo {
public:
  enum Type {
    Cpu = 0,
    Human = 1,
  };

  PlayerInfo ();
  PlayerInfo (GameTurn::players gt);

  void set_turn(const GameTurn::players &c);
  void set_color(const Color &c);
  void set_type(const Type &t);

  Color& get_color();
  Type& get_type();
  GameTurn::players& get_turn();

private:
  Color m_c = NONE;
  Type m_t = Human;
  GameTurn::players m_gt;
};

#endif /* PLAYER_INFO_H */
