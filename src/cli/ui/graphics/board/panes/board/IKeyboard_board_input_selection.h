#ifndef BOARD_INPUT_SELECTION
#define BOARD_INPUT_SELECTION

#include "ui/graphics/board/panes/IUi_board.h"
#include "utils/defs.h"

class IKeyboardBoardInput {
 public:
  virtual ~IKeyboardBoardInput() {}
  virtual void select_next_square(const SquareIndices& sq) = 0;
  virtual void selected_square(const SquareIndices& sq) = 0;
  virtual void deselect_square(const SquareIndices& sq) = 0;
  virtual void update() = 0;
};

#endif // !BOARD_MAIN_PANE_H
