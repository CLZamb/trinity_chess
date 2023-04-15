#ifndef BOARD_KEYBOARD_PANE_H
#define BOARD_KEYBOARD_PANE_H

#include "game/players/player.h"
#include "ui/graphics/board/panes/board/IKeyboard_board_input_selection.h"
#include "ui/graphics/board/panes/board/board_pane.h"
#include "ui/input/board/keyboard/keyboard_input_board_event_handler.hpp"
// #include "ui/input/board/keyboard/keyboard_input_board_event_handler.hpp"

class BoardKeyboardPane : public BoardPane, public IKeyboardBoardInput {
public:
  BoardKeyboardPane(const string &fen)
      : BoardPane(fen), m_even_handler(*this) {}

  virtual ~BoardKeyboardPane() {}

  void update() override { 
    BoardPane::update(); 
  }

  void update_turn(const PlayerInfo& p) override {
    m_even_handler.update_turn(p);
  }

  bool handle_event(KeyCode::Key e, string &callback) override {
    return m_even_handler.handle_event(e, callback);
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
  KeyboardEventHandler m_even_handler;
};

#endif /* BOARD_KEYBOARD_PANE_H */
