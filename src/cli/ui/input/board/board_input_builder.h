#ifndef IBOARD_INPUT_BUILDER_H
#define IBOARD_INPUT_BUILDER_H

#include "ui/input/board/keyboard/keyboard_input_board.h"
// #include "ui/input/board/text/text_input_board.h"
#include "ui/input/input_types/input_types.h"
#include "text/text_input_board.h"

class BoardInputBuilder {
public:
  std::unique_ptr<BoardInput> get_new_board_input(InputType input_type) {
    if (input_type == InputType::Keyboard)
      return std::make_unique<KeyboardInputBoard>();

    return std::make_unique<KeyboardInputBoard>();
  }
};

#endif /* BOARD_INPUT_H */
