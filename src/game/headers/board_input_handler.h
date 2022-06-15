#ifndef BOARD_INPUT_HANLDER_H
#define BOARD_INPUT_HANLDER_H

#include "board/headers/defs.h"
#include "game/headers/game_turn_observer.h"
#include "input/headers/input_event.h"
#include "input/headers/input.h"
#include "view/headers/board_view.h"

class BoardInputHandler : public GameTurnObserver, public InputObserver    {
public:
  BoardInputHandler(Input& i, BoardView &b);

  void update_turn(const PlayerInfo &t) override;
  string get_next_player_string_move();

private:
  enum direction_value {
    DIR_UP    = 8,
    DIR_RIGHT = 1,
    DIR_LEFT  = -DIR_RIGHT,
    DIR_DOWN  = -DIR_UP,
  };

  void handle_input_event(const InputEvent& e) override;
  void handle_type(const InputEvent::Type & t);
  void handle_key_pressed(const InputKeys::Key key);
  void handle_selected_position(const int& p);
  void update_view_select_next_square(const int &next);
  void update_view_selected_square(const int &next);
  void update_view_deselected_square(const int &next);

  array<int, GameTurn::kSize> from_pos{D3, E6};
  array<int, GameTurn::kSize> to_pos{from_pos[GameTurn::player_1],
                                     from_pos[GameTurn::player_2]};

  bool from_pos_selected = false;
  string m_string_player_input = "error";
  Input &m_input;
  BoardView &m_view;
  PlayerInfo m_turn;
  InputEvent m_game_turn_event;
};

#endif /* BOARD_INPUT_HANLDER_H */
