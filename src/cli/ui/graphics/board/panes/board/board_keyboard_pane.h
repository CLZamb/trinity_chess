#ifndef BOARD_KEYBOARD_PANE_H
#define BOARD_KEYBOARD_PANE_H

#include "game/players/player.h"
#include "ui/graphics/board/panes/board/IKeyboard_board_input_selection.h"
#include "ui/graphics/board/panes/board/board_pane.h"
#include "ui/input/board/keyboard/keyboard_input_board.h"
#include "ui/input/board/keyboard/keyboard_input_board_event_handler.hpp"
// #include "ui/input/board/keyboard/keyboard_input_board_event_handler.hpp"

class BoardKeyboardPane : public BoardPane, public IKeyboardBoardInput {
public:
  BoardKeyboardPane(const string &fen, shared_ptr<KeyboardInputBoard> p)
      : BoardPane(fen), m_event_handler(*this) {

    p->bind(Keyboard::W, &KeyboardEventHandler::handle_event_up, &m_event_handler);
    p->bind(Keyboard::A, &KeyboardEventHandler::handle_event_left, &m_event_handler);
    p->bind(Keyboard::S, &KeyboardEventHandler::handle_event_down, &m_event_handler);
    p->bind(Keyboard::D, &KeyboardEventHandler::handle_event_right, &m_event_handler);

    p->bind(Keyboard::UP, &KeyboardEventHandler::handle_event_up, &m_event_handler);
    p->bind(Keyboard::DOWN, &KeyboardEventHandler::handle_event_down, &m_event_handler);
    p->bind(Keyboard::LEFT, &KeyboardEventHandler::handle_event_left, &m_event_handler);
    p->bind(Keyboard::RIGHT, &KeyboardEventHandler::handle_event_right, &m_event_handler);

    p->bind(Keyboard::ENTER, &KeyboardEventHandler::handle_event_enter, &m_event_handler);
  }

  virtual ~BoardKeyboardPane() {}

  void update() override { 
    BoardPane::update_board_drawing(); 
  }

  void make_move(const Move &mv) override {
    BoardPane::make_move(mv);
  }

  void update_turn(const PlayerInfo& p) override {
    m_event_handler.update_turn(p);
  }

  bool has_events() override {
    return m_event_handler.is_completed();
  }

  string get_string() override {
    return m_event_handler.get_string();
  }

  void select_next_square(const SquareIndices &new_pos) override {
    m_squares_drawings[prev_pos].deselect();
    prev_pos = new_pos;
    m_squares_drawings[new_pos].select();
  }

  void selected_square(const SquareIndices &sq) override {
    if (m_squares_drawings[sq].is_selected())
      return;

    m_squares_drawings[sq].select();
    m_squares_drawings[sq].set_is_selected(true);
  }

  void deselect_square(const SquareIndices &sq) override {
    if (!m_squares_drawings[sq].is_selected())
      return;

    m_squares_drawings[sq].set_is_selected(false);
    m_squares_drawings[sq].deselect();
  }

private:
  SquareIndices prev_pos{SquareNull};
  KeyboardEventHandler m_event_handler;
};

#endif /* BOARD_KEYBOARD_PANE_H */
