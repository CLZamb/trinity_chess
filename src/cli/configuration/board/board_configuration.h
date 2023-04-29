#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <string>

#include "game/game_typedefs.h"
#include "ui/input/input_types.h"

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
  // const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
  // const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
  // const string start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0";
  // const string start_fen = "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1";
  // const string start_fen = "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1";
  // const string start_fen = "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1";
  // const string start_fen = "6k1/5Q2/8/8/8/8/7R/6K1 b - - 0 1";
  // const std::string m_start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0";
  const std::string m_start_fen =
      "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  Color m_initial_side{Color::WHITE};
};

#endif /* PLAYER_CONFIG_H */
