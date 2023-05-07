#ifndef MENU_H
#define MENU_H

#include <memory>
#include <string>

#include "menu/menu_window/menu_components.hpp"
#include "options.hpp"
#include "input/input_components.h"
#include "input/input_types.h"

template <typename T = std::string>
class MenuWindow : public Window {
 public:
  explicit MenuWindow(InputType input_type,
                      const std::string title = "",
                      const Options<T> &opts = {})
      : m_opts(opts)
      , m_pane(title, format_options()) {
    input_type == InputType::Keyboard ? set_keyboard() : set_text();
    add_left_pane(&m_pane);
  }

  void set_input(InputType input_type) {
    input_type == InputType::Keyboard ? set_keyboard() : set_text();
  }

  void set_title(const std::string &title) { m_pane.set_title(title); }

  void add_options(const Options<T> &options) {
    m_opts = options;
    m_pane.set_options(format_options());
    p_event_handler->options_added();
  }

  void add_option(std::string option) {
    m_opts.add_option(cur_index, {cur_index, option});
    m_pane.set_option(format_option(cur_index, option));
    p_event_handler->options_added();

    cur_index++;
  }

  const T &select_option() { return get_menu_option().opt; }

  const int &select_option_by_number_key() { return get_menu_option().num; }

  void print() { Window::print(); }

 private:
  void set_keyboard() {
    p_input = InputComponents::new_input_keyboard();
    p_event_handler = MenuComponents::new_keyboard_handler(p_input, m_pane, m_opts);
  }

  void set_text() {
    p_input = InputComponents::new_input_text("\t\t\t\t>> ");
    p_event_handler = MenuComponents::new_text_handler(p_input, m_pane, m_opts);
  }

  const Option<T> &get_menu_option() {
    do {
      p_input->listen_for_input_events();

      if (!p_event_handler->has_events()) {
        break;
      }

      this->print();

    } while (true);

    return p_event_handler->selected_menu_option();
  };

  std::string format_option(int index, const std::string desc) {
    return std::to_string(index) + ". " + desc;
  }

  std::list<std::string> format_options() {
    std::list<std::string> options_formatted;
    for (auto i : m_opts) {
      options_formatted.push_back(format_option(i.second.num, i.second.desc));
    }
    return options_formatted;
  }

  int cur_index = 1;
  Options<T> m_opts;
  MenuPane m_pane;
  std::unique_ptr<Input> p_input;
  std::unique_ptr<IMenuEventHandler<T>> p_event_handler;
};

#endif /* MENU_H */
