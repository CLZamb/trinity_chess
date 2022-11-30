#ifndef KEYBOARD_INPUT_PLAYER_H
#define KEYBOARD_INPUT_PLAYER_H

#include "input/headers/keyboard_base.h"
#include "view/headers/board_view.h"
#include "input/headers/input_type.h"
#include <unordered_map>

class KeyboardInputPlayer : public PlayerInput {
  public:
    enum direction_value {
      DIR_UP    = 8,
      DIR_RIGHT = 1,
      DIR_LEFT  = -DIR_RIGHT,
      DIR_DOWN  = -DIR_UP,
    };

    KeyboardInputPlayer(KeyboardBase& ki);
    void update_turn(const PlayerInfo & p) override;
    void setup(BoardView& v) override;
    string get_player_string_move(PlayerPosition&) override; 

  private:
    string select_position(PlayerPosition &p,const size_t &pos);
    void update_view_select_next_square(const size_t &position);
    void update_view_selected_square(const size_t &position);
    void update_view_deselected_square(const size_t &position);
    void select_from(PlayerPosition &p,const size_t pos);
    void select_to(PlayerPosition &p,const size_t pos);
    void handle_arrow_keys(const InputKeys::Key&, size_t& pos);
    void update_last_position(const size_t &pos);
    void deselect_all_previous_selected_squares();

    static const string key_not_supported;
    PlayerInfo m_turn;
    KeyboardBase& m_k_input;
    BoardView* m_view;
    bool completed{false};
    bool has_been_selected{false};
    unordered_map<InputKeys::Key, int> m_direction_value {
      {InputKeys::UP,    DIR_UP},
      {InputKeys::DOWN,  DIR_DOWN},
      {InputKeys::LEFT,  DIR_LEFT},
      {InputKeys::RIGHT, DIR_RIGHT},
      {InputKeys::W,     DIR_UP},
      {InputKeys::A,     DIR_LEFT},
      {InputKeys::S,     DIR_DOWN},
      {InputKeys::D,     DIR_RIGHT},
    };
    unordered_map<GameTurn::Players, size_t> last_position {
      {GameTurn::player_1, D3},
      {GameTurn::player_2, E6},
    };

    list<size_t> selected_positions;
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
