#ifndef BOARD_KEYBOARD_PANE_H
#define BOARD_KEYBOARD_PANE_H

#include "board_pane.h"
#include "ui/graphics/board/IKeyboard_board_input_selection.h"

class BoardKeyboardPane : public BoardPane,
                          public IKeyboardBoardInput {
public:
  BoardKeyboardPane(const string &fen) : BoardPane(fen) {}

  virtual ~BoardKeyboardPane() {}

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
};

#endif /* BOARD_KEYBOARD_PANE_H */
