#ifndef MENU_COMPONENTS_H
#define MENU_COMPONENTS_H

#include <memory>

#include "menu/menu_window/event_handlers/menu_keyboard_event_handler.h"
#include "menu/menu_window/event_handlers/menu_text_event_handler.h"

namespace MenuComponents {

template <typename T>
inline auto new_keyboard_handler(const std::unique_ptr<Input> &input,
                                 MenuPane &menu_pane,
                                 Options<T> &options) {
  return std::make_unique<MenuKeyboardEventHandler<T>>(input, menu_pane,
                                                       options);
}

template <typename T>
inline auto new_text_handler(const std::unique_ptr<Input> &input,
                             MenuPane &menu_pane,
                             Options<T> &options) {
  return std::make_unique<MenuTextEventHandler<T>>(input, menu_pane, options);
}

}   // namespace MenuComponents
#endif /* MENU_COMPONENTS_H */
