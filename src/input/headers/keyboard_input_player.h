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
    string get_player_string_move(BoardView&, HumanPlayer&) override; 

  private:
    string select_position(HumanPlayer &p,const int pos);
    void update_view_select_next_square(BoardView& v, const int &position);
    void update_view_selected_square(BoardView& v, const int &position);
    void update_view_deselected_square(BoardView& v, const int &position);
    void select_from(HumanPlayer &p,const int pos);
    void select_to(HumanPlayer &p,const int pos);
    void handle_arrow_keys(const InputKeys::Key&, int& pos);

    PlayerInfo m_turn;
    KeyboardBase& m_k_input;
    static const string key_not_supprted;
    bool completed{false};
    bool has_been_selected{false};
    unordered_map<InputKeys::Key, int> m_direction_value {
      {InputKeys::UP,   DIR_UP},
      {InputKeys::DOWN, DIR_DOWN},
      {InputKeys::LEFT, DIR_LEFT},
      {InputKeys::RIGHT, DIR_RIGHT},
    };
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
