#ifndef INPUT_COMPONENTS_H
#define INPUT_COMPONENTS_H

#include <memory>

#include "board/board_window/board_pane/event_handlers/keyboard_event_handler.h"
#include "board/board_window/board_pane/event_handlers/text_event_handler.h"
#include "input/keyboard/keyboard_input.h"
#include "input/text/text_input.h"

namespace InputComponents {
using std::unique_ptr;

inline auto new_input_keyboard() { return std::make_unique<KeyboardInput>(); }

inline auto new_input_text(const std::string string_before_prompt) {
  return std::make_unique<TextInput>(string_before_prompt);
}

inline auto new_input_board(InputType type) -> unique_ptr<InputComponent> {
  switch (type) {
    case InputType::Text:
      return new_input_text(" >> ");
    case InputType::Keyboard:
      return new_input_keyboard();
    default:
      return nullptr;
  }
}

}   // namespace InputComponents

#endif /* INPUT_COMPONENTS_H */
