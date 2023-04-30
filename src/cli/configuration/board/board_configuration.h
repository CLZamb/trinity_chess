#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <string>

#include "game/game_typedefs.h"
#include "input/input_types.h"

class BoardConfig {
 public:
  BoardConfig();
  virtual ~BoardConfig();

  const std::string &get_fen() { return m_start_fen; }

  InputType get_input_type() const;
  void set_input_type(InputType i);

  void set_initial_color(Color c);
  Color &get_initial_color();

 private:
  InputType m_input_type{Keyboard};
  const std::string m_start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0 1";
  Color m_initial_side{Color::WHITE};
};

#endif /* PLAYER_CONFIG_H */
