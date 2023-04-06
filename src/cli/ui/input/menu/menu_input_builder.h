#ifndef MENU_INPUT_BUILDER_H
#define MENU_INPUT_BUILDER_H

#include <memory>
#include "ui/input/menu/keyboard/keyboard_input_menu.h"
#include "ui/input/menu/text/text_input_menu.hpp"
#include "ui/input/input_types/input_types.h"


template<typename T>
class MenuInputBuilder {
public:
  std::unique_ptr<MenuInput<T>> get_new_menu_input(InputType input_type, MenuView& v, Options<T> &o) {
    if (input_type == InputType::Keyboard)
      return std::make_unique<KeyboardInputMenu<T>>(v, o);

    return std::make_unique<TextInputMenu<T>>(v, o);
  }
};

#endif /* MENU_INPUT_BUILDER_H */
