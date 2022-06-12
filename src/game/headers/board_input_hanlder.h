#ifndef BOARD_INPUT_HANLDER_H
#define BOARD_INPUT_HANLDER_H

#include "game/headers/game_turn_observer.h"
#include "input/headers/input_event.h"
#include "player/headers/input.h"
#include "view/headers/board_view.h"

class BoardInputHanlder : public GameTurnObserver, public InputObserver    {
public:
  BoardInputHanlder(Input& i, BoardView &b);

  void update_turn(const PlayerInfo &t) override;
  void next_position();

  string get_next_player_string_move();

private:
  enum direction_value {
    DIR_UP    = 8,
    DIR_RIGHT = 1,
    DIR_LEFT  = -DIR_RIGHT,
    DIR_DOWN  = -DIR_UP,
  };

  void handle_input_event(const InputEvent& e) override;
  void handle_key_pressed(const InputKeys::Key key);

  array<int, GameTurn::kSize> pos = {A1, H8};
  array<int, GameTurn::kSize> from_pos = {A1, H8};
  string m_string_player_input = "error";
  Input &m_input;
  BoardView &m_view;
  PlayerInfo m_turn;
};

#endif /* BOARD_INPUT_HANLDER_H */
