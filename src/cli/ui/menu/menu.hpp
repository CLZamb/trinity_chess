#ifndef MENU_H
#define MENU_H

#include "menu_pane.hpp"
#include "options.hpp"
#include "ui/input/input.h"
#include "ui/input/input_types.h"
#include "ui/menu/event_handlers/menu_keyboard_event_handler.h"
#include "ui/menu/event_handlers/menu_text_event_handler.h"
#include <memory>

template <typename T = string> 
class Menu : public Window {
public:
  Menu(InputType input_type, const string title = "", const Options<T> &opts = {}) : 
    m_opts(opts),
    m_pane(title, format_options()) {
    input_type == Keyboard ? set_keyboard() : set_text();
    add_left_pane(&m_pane);
  }

  virtual ~Menu() {}

  void set_title(const string &s) { 
    m_pane.set_title(s); 
  }

  void add_options(const Options<T> &m) { 
    m_opts = m;
    m_pane.set_options(format_options());
    p_event_handler->options_added();
  }

  const T &select_option() { 
    return get_menu_option().opt;
  }

  const int &select_option_by_number_key() { 
    return get_menu_option().num;
  }

  void print() {  
    Window::print();
  }

private:
  void set_keyboard() {
    auto keyboard_input = std::make_shared<KeyboardInput>();
    p_event_handler = std::make_unique<MenuKeyboardEventHandler<T>>(keyboard_input, m_pane, m_opts);
    p_input = keyboard_input;
  }

  void set_text() {
    auto text_input = std::make_shared<TextInput>();
    p_event_handler = std::make_unique<MenuTextEventHandler<T>>(text_input, m_pane, m_opts);
    p_input = text_input;
  }

  const Option<T>& get_menu_option() {
    do {

      p_input->get_input_event();

      if (!p_event_handler->has_events())
        break;

      Window::print();

    } while (true);

    return p_event_handler->selected_menu_option();
  };

  list<std::string> format_options() {
    list<string> options_formatted;
    for (auto i : m_opts) {
      options_formatted.push_back(
          std::to_string(i.second.num) 
          + ". " +
          i.second.desc);
    }
    return options_formatted;
  }

  Options<T> m_opts;
  MenuPane m_pane;
  std::shared_ptr<Input> p_input;
  std::unique_ptr<IMenuEventHandler<T>> p_event_handler;
};

#endif /* MENU_H */
