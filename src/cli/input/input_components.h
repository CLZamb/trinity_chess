#ifndef INPUT_COMPONENTS_H
#define INPUT_COMPONENTS_H

#include <memory>

#include "input/keyboard/keyboard_input.h"
#include "input/text/text_input.h"

namespace InputComponents {

inline auto new_input_keyboard() { return std::make_unique<KeyboardInput>(); }

inline auto new_input_text(const string string_before_prompt) {
  auto text_input = std::make_unique<TextInput>();
  text_input->set_string_before_prompt(string_before_prompt);
  return text_input;
}

}   // namespace InputComponents

#endif /* INPUT_COMPONENTS_H */
