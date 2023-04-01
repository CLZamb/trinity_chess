#ifndef MENU_H
#define MENU_H

#include "input/keyboard/arrow_input.h"
#include "input/text/text_input.h"
// #include "ui/input/keyinput_event.h"
#include "input/text/text_input.h"
#include "input/text/text_input_menu.h"
#include "options.hpp"
#include "input/keyboard/Arrow_input_menu.h"
#include "menu_view.hpp"
#include <unordered_map>
#include <string>

template <typename T = string> 
class Menu {
public:
  Menu(const ArrowInput &&) = delete;
  Menu(const TextInput &&) = delete;

  Menu(ArrowInput &a_input) :
    p_input(std::make_unique<ArrowInputMenu<T>>(a_input, m_view, m_opts)) {}

  Menu(ArrowInput &a_input, const string title, const Options<T> &opts) :
    m_opts(opts),
    m_view(title, format_options()),
    p_input(std::make_unique<ArrowInputMenu<T>>(a_input, m_view, m_opts)) {
  }

  Menu(TextInput &k_input) :
    p_input(std::make_unique<TextInputMenu<T>>(k_input, m_view, m_opts)) {}

  Menu(TextInput &t_input, const string title, const Options<T> &opts) : 
    m_opts(opts),
    m_view(title, format_options()),
    p_input(std::make_unique<TextInputMenu<T>>(t_input, m_view, m_opts)) {
  }

  virtual ~Menu() {}

  void set_title(const string &s) { m_view.set_title(s); }

  template <typename U> 
  void add_options(const Options<U> &m) {
    m_opts = m;
    m_view.set_options(format_options());
    m_view.selected_option(m_opts.begin()->first);
  }

  void add_options(const Options<T> &m) { 
    m_opts = m;
    m_view.set_options(format_options());
    m_view.selected_option(m_opts.begin()->first);
  }

  const T &select_option() { 
    return p_input->select_menu_option().opt;
  }

  const int &select_option_by_number_key() { 
    return p_input->select_menu_option().num;
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
  std::unique_ptr<MenuInput<T>> p_input;
};

#endif /* MENU_H */
