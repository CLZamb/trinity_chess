#ifndef KEYBOARD_INPUT_MENU_H
#define KEYBOARD_INPUT_MENU_H

#include "ui/input/keyboard/keyboard_input.h"
#include "ui/input/keyboard/keyboard_base.h"
#include "IMenu_event_handler.h"
#include "ui/menu/options.hpp"
#include "ui/menu/menu_pane.hpp"
#include <iostream>

template<typename T>
class MenuKeyboardEventHandler : public IMenuEventHandler<T> {
 public:
  MenuKeyboardEventHandler(shared_ptr<KeyboardInput> p, MenuPane& v, Options<T> &o) :
    m_pane(v), 
    m_opts(o) {

    p->bind(Keyboard::W, &MenuKeyboardEventHandler::handle_event_up, this);
    p->bind(Keyboard::S, &MenuKeyboardEventHandler::handle_event_down, this);
    p->bind(Keyboard::UP, &MenuKeyboardEventHandler::handle_event_up, this);
    p->bind(Keyboard::DOWN, &MenuKeyboardEventHandler::handle_event_down, this);
    p->bind(Keyboard::ENTER, &MenuKeyboardEventHandler::handle_event_enter, this);

    p_selection_option = m_opts.begin();
    m_pane.selected_option(p_selection_option->first);
  }

  virtual ~MenuKeyboardEventHandler() = default;

  const Option<T>& selected_menu_option() override { 
    return p_selection_option->second;
  }

  void options_added() override {
    p_selection_option = m_opts.begin();
    m_pane.selected_option(p_selection_option->first);
  }

  bool has_events() override {
    return has_more_events;
  }

 private:
  void handle_event_up(CommandEvent&) {
    if(p_selection_option != m_opts.begin())
      --p_selection_option;

    m_pane.selected_option(p_selection_option->first);
  }

  void handle_event_down(CommandEvent&) {
    if(p_selection_option != (--m_opts.end()))
      ++p_selection_option;

    m_pane.selected_option(p_selection_option->first);
  }

  void handle_event_enter(CommandEvent&) {
    has_more_events = false;
  }

  typename Options<T>::iterator p_selection_option;
  bool has_more_events{true};
  MenuPane& m_pane;
  Options<T>& m_opts;
};


#endif /* KEYBOARD_INPUT_MENU_H */
