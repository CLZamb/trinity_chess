#ifndef KEYBOARD_INPUT_PLAYER_H
#define KEYBOARD_INPUT_PLAYER_H

#include <unordered_map>
#include "game/players/player_position.h"
#include "ui/graphics/board/board_view.h"
#include "ui/input/board/board_input.h"
#include "ui/input/input_types/keyboard/keyboard_input.h"
#include "ui/input/input_types/keyboard/keyboard_key.h"

class KeyboardInputBoard : public BoardInput {
  public:
    enum direction_value {
      DIR_UP    = 8,
      DIR_RIGHT = 1,
      DIR_LEFT  = -DIR_RIGHT,
      DIR_DOWN  = -DIR_UP,
    };

    KeyboardInputBoard();
    virtual ~KeyboardInputBoard(){}
    string get_next_string_move(BoardView& bv) override; 

  private:
    string select_position(const size_t &pos);
    void update_view_select_next_square(const size_t &position, BoardView& bv);
    void update_view_selected_square(const size_t &position, BoardView& bv);
    void update_view_deselected_square(const size_t &position, BoardView& bv);
    void select_from(const size_t pos);
    void select_to(const size_t pos);
    void handle_arrow_keys(const Keyboard::Key key, size_t& pos);
    void update_last_position(const size_t &pos);
    void deselect_all_previous_selected_squares(BoardView& bv);

    static const string key_not_supported;
    KeyboardInput m_k_input;
    PlayerPosition m_player_pos;

    bool completed{false};
    bool has_been_selected{false};

    unordered_map<Keyboard::Key, int> m_direction_value {
      {Keyboard::UP,    DIR_UP},
      {Keyboard::DOWN,  DIR_DOWN},
      {Keyboard::LEFT,  DIR_LEFT},
      {Keyboard::RIGHT, DIR_RIGHT},
      {Keyboard::W,     DIR_UP},
      {Keyboard::A,     DIR_LEFT},
      {Keyboard::S,     DIR_DOWN},
      {Keyboard::D,     DIR_RIGHT},
    };

    list<size_t> selected_positions;
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
