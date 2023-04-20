#ifndef BOARD_KEYBOARD_PANE_H
#define BOARD_KEYBOARD_PANE_H

#include "game/players/player_position.h"
#include "game/turn/game_turn_observer.h"
#include "ui/board/board_pane/board_pane.h"
#include "ui/input/keyboard/keyboard_input.h"
#include "IBoard_event_handler.hpp"

class BoardKeyboardEventHandler : public IBoardEventHandler, public GameTurnObserver  {
 public:
  BoardKeyboardEventHandler(shared_ptr<BoardPane> b, shared_ptr<Input> p)
      : p_board_pane(b) {

    p->bind(Keyboard::W, &BoardKeyboardEventHandler::handle_event_direction, this);
    p->bind(Keyboard::A, &BoardKeyboardEventHandler::handle_event_direction, this);
    p->bind(Keyboard::S, &BoardKeyboardEventHandler::handle_event_direction, this);
    p->bind(Keyboard::D, &BoardKeyboardEventHandler::handle_event_direction, this);

    p->bind(Keyboard::UP, &BoardKeyboardEventHandler::handle_event_direction, this);
    p->bind(Keyboard::DOWN, &BoardKeyboardEventHandler::handle_event_direction, this);
    p->bind(Keyboard::LEFT, &BoardKeyboardEventHandler::handle_event_direction, this);
    p->bind(Keyboard::RIGHT, &BoardKeyboardEventHandler::handle_event_direction, this);

    p->bind(Keyboard::ENTER, &BoardKeyboardEventHandler::handle_event_enter, this);
  }

  virtual ~BoardKeyboardEventHandler() {}

  void update_turn(const PlayerInfo& p) override {
    m_player_color = p.color;

    SquareIndices last_pos = m_player_pos.get_last_position(m_player_color);
    update_next_square(last_pos);

    has_been_selected = false;
    completed = false;
  }

  bool has_events() override {
    return !completed;
  }

  string get_string() override {
    return std::move(call_back);
  }

 private:

  void update_next_square(const SquareIndices next_pos) {
    p_board_pane->update_select_next_square(next_pos);
    m_player_pos.update_next_last_position(next_pos);
  }

  void handle_event_direction(CommandEvent& e) {
    int dir_value = m_direction_value.at(e.get_key_code());
    int cur_pos = static_cast<int>(m_player_pos.get_next_last_position());
    int next_pos = cur_pos + dir_value;

    if (is_next_position_out_of_bounds(next_pos)) {
      std::cout << "next position is out of bound" << std::endl;
      return;
    }

    update_next_square(static_cast<SquareIndices>(next_pos));
  }

  void handle_event_enter(CommandEvent&) { 
    completed = false;
    SquareIndices next_pos = m_player_pos.get_next_last_position();

    call_back += select_position(next_pos);
    p_board_pane->update_selected_square(next_pos);

    if (completed) {
      p_board_pane->deselect_all_previous_selected_squares();
      m_player_pos.update_last_position(m_player_color);
      has_been_selected = false;
    }
  }

  string select_position(const SquareIndices &pos) {
    completed = has_been_selected;

    has_been_selected = !has_been_selected;
    return string_utils::squareindex_to_str(SquareIndices(pos));
  }

  bool is_next_position_out_of_bounds(int next_pos) {
    return (next_pos < square_A1) || (next_pos > square_H8);
  }

  const string key_not_supported = "key not supported\n";

  enum direction_value {
    DIR_UP = 8,
    DIR_RIGHT = 1,
    DIR_DOWN = -DIR_UP,
    DIR_LEFT = -DIR_RIGHT,
  };

 const unordered_map<KeyCode::Key, int> m_direction_value {
    {KeyCode::UP,    DIR_UP},
    {KeyCode::DOWN,  DIR_DOWN},
    {KeyCode::LEFT,  DIR_LEFT},
    {KeyCode::RIGHT, DIR_RIGHT},
  };

  static const int square_A1{A1};
  static const int square_H8{H8};

  Color m_player_color;
  bool has_been_selected{false};
  bool completed{false};
  PlayerPosition m_player_pos;

  string call_back{""};
  shared_ptr<BoardPane> p_board_pane;
};

#endif /* BOARD_KEYBOARD_PANE_H */
