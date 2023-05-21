#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include <iostream>
#include <unordered_map>

#include "board/chess/position/position_typedefs.h"
#include "game/game_typedefs.h"
#include "input/keyboard/keyboard_keycode.h"

class PlayerPosition {
 public:
  explicit PlayerPosition(Color starting_side)
      : m_side(starting_side) {}
  virtual ~PlayerPosition() {}

  void switch_side() {
    m_side = m_side == Color::WHITE ? Color::BLACK : Color::WHITE;
  }

  const Square &get_cur_position() const { return m_cur_position[m_side]; }

  const Square &get_next_position(KeyCode::Key key) {
    if (is_not_dir_key_code(key)) return m_cur_position[m_side];

    int cur_pos = static_cast<int>(m_cur_position[m_side]);
    int next_pos = cur_pos + m_direction_value.at(key);

    if (is_next_position_out_of_bounds(next_pos)) return m_cur_position[m_side];

    m_cur_position[m_side] = static_cast<Square>(next_pos);
    return m_cur_position[m_side];
  }

 private:
  bool is_not_dir_key_code(const KeyCode::Key &key) {
    bool invalid_key = m_direction_value.find(key) == m_direction_value.end();

    if (invalid_key) { std::cout << "key not supported" << std::endl; }

    return invalid_key;
  }

  bool is_next_position_out_of_bounds(int next_pos) {
    bool is_out_of_bounds = (next_pos < square_A1) || (next_pos > square_H8);

    if (is_out_of_bounds) {
      std::cout << "next position is out of bound" << std::endl;
    }

    return is_out_of_bounds;
  }
  enum direction_value {
    DIR_UP = 8,
    DIR_RIGHT = 1,
    DIR_DOWN = -DIR_UP,
    DIR_LEFT = -DIR_RIGHT,
  };

  const std::unordered_map<KeyCode::Key, int> m_direction_value{
      {   KeyCode::UP,    DIR_UP},
      { KeyCode::DOWN,  DIR_DOWN},
      { KeyCode::LEFT,  DIR_LEFT},
      {KeyCode::RIGHT, DIR_RIGHT},
  };

  static const int square_A1{A1};
  static const int square_H8{H8};

  Color m_side{Color::NONE};
  std::array<Square, Color::SIZE> m_cur_position{D3, E6};
};

#endif /* PLAYER_POSITION_H */
