#ifndef MENU_H
#define MENU_H

#include "game/headers/menu_input_handler.h"
#include "input/headers/input_event.h"
#include "options.h"
#include "input/headers/keyboard_input.h"
#include "view/headers/menu_view.h"
#include <unordered_map>

template <typename T> 
class Menu {
public:
  Menu(Input &input) : 
    m_input_handler(input, m_view, m_opts) {}

  Menu(Input &input, const Options<T> &opts) : 
    m_opts(opts),
    m_view(format_options()),
    m_input_handler(input, m_view, m_opts) {}

  Menu(Input &input, const string title, const Options<T> &opts) : 
    Menu(input, opts) {
    m_view.set_title(title);
  }

  virtual ~Menu() {}

  void set_title(const string &s) { m_view.set_title(s); }
  void add_options(const Options<T> &m_opts) { this->m_opts = m_opts; }
  const T &select_option() { return m_input_handler.select_option(); }

  void print() { m_view.print(); }
private:
  list<string> format_options() {
    list<string> options_formatted;
    for (auto i : m_opts.get_options()) {
      options_formatted.push_back(
          std::to_string(i.second.num) 
          + ". " +
          i.second.desc);
    }
    return options_formatted;
  }

  Options<T> m_opts;
  MenuView m_view;
  MenuInputHandler<T> m_input_handler;
};

#endif /* MENU_H */
