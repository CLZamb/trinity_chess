#ifndef MENU_H
#define MENU_H

#include "input/headers/input_event.h"
#include "input/headers/text_input.h"
#include "input/headers/text_input_menu.h"
#include "options.h"
#include "input/headers/keyboard_input.h"
#include "view/headers/menu_view.h"
#include <unordered_map>
#include <string>


template <typename T> 
class Menu {
public:
  Menu(const KeyboardInput &&) = delete;

  Menu(KeyboardInput &k_input, const string title, const Options<T> &opts) :
    m_opts(opts),
    m_view(format_options()),
    m_m_input(std::make_unique<KeyboardInputMenu<T>>(k_input, m_view, m_opts)) {
    m_view.set_title(title);
  }

  Menu(TextInput &t_input, const string title, const Options<T> &opts) : 
    m_opts(opts),
    m_view(format_options()),
    m_m_input(std::make_unique<TextInputMenu<T>>(t_input, m_view, m_opts)) {
    m_view.set_title(title);
  }

  virtual ~Menu() {}

  void set_title(const string &s) { m_view.set_title(s); }
  void add_options(const Options<T> &m_opts) { this->m_opts = m_opts; }

  const T &select_option() { 
    return m_m_input->select_menu_option().opt;
  }

  void print() { m_view.print(); }

private:
  list<string> format_options() {
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
  MenuView m_view;
  std::unique_ptr<MenuInput<T>> m_m_input;
  // MenuInput& m_input;
};


#endif /* MENU_H */
