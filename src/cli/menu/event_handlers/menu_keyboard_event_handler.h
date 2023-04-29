#ifndef KEYBOARD_INPUT_MENU_H
#define KEYBOARD_INPUT_MENU_H

#include "IMenu_event_handler.h"
#include "menu/menu_window/menu_pane.h"
#include "menu/menu_window/options.hpp"
#include "ui/input/keyboard/keyboard_base.h"
#include "ui/input/keyboard/keyboard_input.h"

template <typename T>
class MenuKeyboardEventHandler : public IMenuEventHandler<T> {
 public:
  MenuKeyboardEventHandler(const std::unique_ptr<KeyboardInput>& p, MenuPane &v,
                           Options<T> &o)
      : m_pane(v), m_opts(o) {
    p->bind<CommandEventKeyboard>(
        &MenuKeyboardEventHandler::handle_keyboard_event, this);

    p_selection_option = m_opts.begin();
    m_pane.selected_option(p_selection_option->first);
  }

  virtual ~MenuKeyboardEventHandler() = default;

  const Option<T> &selected_menu_option() override {
    return p_selection_option->second;
  }

  void options_added() override {
    p_selection_option = m_opts.begin();
    m_pane.selected_option(p_selection_option->first);
  }

  bool has_events() override { return has_more_events; }

 private:
  void handle_keyboard_event(CommandEventKeyboard &e) {
    KeyCode::Key keycode = e.get_key_code();

    switch (keycode) {
      case KeyCode::UP:
        handle_event_up();
        break;
      case KeyCode::DOWN:
        handle_event_down();
        break;
      case KeyCode::ENTER:
        handle_event_enter();
        break;
      default:
        m_pane.set_error("key not supported");
        break;
    }
  }
  void handle_event_up() {
    if (p_selection_option != m_opts.begin()) {
      --p_selection_option;
    }

    m_pane.selected_option(p_selection_option->first);
  }

  void handle_event_down() {
    if (p_selection_option != (--m_opts.end())) {
      ++p_selection_option;
    }

    m_pane.selected_option(p_selection_option->first);
  }

  void handle_event_enter() { has_more_events = false; }

  typename Options<T>::iterator p_selection_option;
  bool has_more_events{true};
  MenuPane &m_pane;
  Options<T> &m_opts;
};

#endif /* KEYBOARD_INPUT_MENU_H */
