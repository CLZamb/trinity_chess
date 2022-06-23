#include "input/headers/keyboard_input_player.h"

const string KeyboardInputPlayer::key_not_supprted = "key not supported\n";

KeyboardInputPlayer::KeyboardInputPlayer(KeyboardBase &k) : m_k_input(k) {}

void KeyboardInputPlayer::update_turn(const PlayerInfo &t) { 
  m_turn = t; 
}

void KeyboardInputPlayer::setup(BoardView &v) {
  v.selected_square(0);
  v.print();
}

string KeyboardInputPlayer::get_player_string_move(BoardView &v, HumanPlayer& player) { 
  completed = false;
  has_been_selected = false;

  string next_move{""};
  int next_pos = player.get_to_position();

  while(!completed) {
    switch(m_k_input.read_key()) {
      case InputKeys::ARROW_KEY:
        handle_arrow_keys(m_k_input.read_arrow_key(), next_pos);
        break;
      case InputKeys::ENTER:
        next_move += select_position(player, next_pos);
        update_view_selected_square(v, next_pos);
        break;
      default:
        std::cout << key_not_supprted  << std::endl;
        break;
    }

    update_view_select_next_square(v, next_pos);
    v.print();
  }

  return next_move; 
}

void KeyboardInputPlayer::handle_arrow_keys(const InputKeys::Key& k, int& pos) {
  int prev = pos;
  pos += m_direction_value[k];

  if (pos < A1 || pos > H8) pos = prev;
}

string KeyboardInputPlayer::select_position(HumanPlayer& p, const int pos) {
  if (has_been_selected) {
    select_to(p, pos); 
  } else {
    select_from(p, pos);
  }

  has_been_selected = !has_been_selected;
  return string_utils::squareindex_to_str(SquareIndices(pos));
}

void KeyboardInputPlayer::select_from(HumanPlayer& p, const int pos) {
  p.set_from_poistion(pos);
}

void KeyboardInputPlayer::select_to(HumanPlayer& p, const int pos) {
  completed = true;
  p.set_to_position(pos);
}

void KeyboardInputPlayer::update_view_select_next_square(BoardView &v, const int &next) {
  v.select_next_square(next);
}
void KeyboardInputPlayer::update_view_selected_square(BoardView &v,
                                                      const int &p) {
  v.selected_square(p);
}
void KeyboardInputPlayer::update_view_deselected_square(BoardView &v,
                                                        const int &p) {
  v.deselect_square(p);
}
