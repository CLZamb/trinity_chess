#ifndef KEYBOARD_INPUT_PLAYER_H
#define KEYBOARD_INPUT_PLAYER_H

#include <unordered_map>
#include "game/players/player_position.h"
#include "ui/graphics/board/board_view.h"
#include "ui/input/board/board_input.h"
#include "ui/input/input_types/keyboard/keyboard_input.h"

class KeyboardInputBoard : public BoardInput {
  public:
    enum direction_value {
      DIR_UP    = 8,
      DIR_RIGHT = 1,
      DIR_LEFT  = -DIR_RIGHT,
      DIR_DOWN  = -DIR_UP,
    };

    KeyboardInputBoard(BoardView& bv);
    string get_next_string_move() override; 

  private:
    string select_position(const size_t &pos);
    void update_view_select_next_square(const size_t &position);
    void update_view_selected_square(const size_t &position);
    void update_view_deselected_square(const size_t &position);
    void select_from(const size_t pos);
    void select_to(const size_t pos);
    void handle_arrow_keys(const InputKeyboardKeys::Key&, size_t& pos);
    void update_last_position(const size_t &pos);
    void deselect_all_previous_selected_squares();

    static const string key_not_supported;
    KeyboardInput m_k_input;
    BoardView& m_board_view;
    PlayerPosition m_player_pos;

    bool completed{false};
    bool has_been_selected{false};

    unordered_map<InputKeyboardKeys::Key, int> m_direction_value {
      {InputKeyboardKeys::UP,    DIR_UP},
      {InputKeyboardKeys::DOWN,  DIR_DOWN},
      {InputKeyboardKeys::LEFT,  DIR_LEFT},
      {InputKeyboardKeys::RIGHT, DIR_RIGHT},
      {InputKeyboardKeys::W,     DIR_UP},
      {InputKeyboardKeys::A,     DIR_LEFT},
      {InputKeyboardKeys::S,     DIR_DOWN},
      {InputKeyboardKeys::D,     DIR_RIGHT},
    };

    list<size_t> selected_positions;
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
