#ifndef MENU_H
#define MENU_H

#include "input/headers/input_event.h"
#include "input/headers/arrow_input.h"
#include "input/headers/text_input.h"
#include "input/headers/text_input_menu.h"
#include "options.h"
#include "input/headers/Arrow_input_menu.h"
#include "view/headers/menu_view.h"
#include <unordered_map>
#include <string>


template <typename T> 
class Menu {
public:
  Menu(const ArrowInput &&) = delete;
  Menu(const TextInput &&) = delete;

  Menu(ArrowInput &a_input) :
    m_m_input(std::make_unique<ArrowInputMenu<T>>(a_input, m_view, m_opts)) {}

  Menu(ArrowInput &a_input, const string title, const Options<T> &opts) :
    m_opts(opts),
    m_view(title, format_options()),
    m_m_input(std::make_unique<ArrowInputMenu<T>>(a_input, m_view, m_opts)) {
  }

  Menu(TextInput &k_input) :
    m_m_input(std::make_unique<TextInputMenu<T>>(k_input, m_view, m_opts)) {}

  Menu(TextInput &t_input, const string title, const Options<T> &opts) : 
    m_opts(opts),
    m_view(title, format_options()),
    m_m_input(std::make_unique<TextInputMenu<T>>(t_input, m_view, m_opts)) {
  }

  virtual ~Menu() {}

  void set_title(const string &s) { m_view.set_title(s); }

  void add_options(const Options<T> &m) { 
    m_opts = m;
    m_view.set_options(format_options());
    m_view.selected_option(m_opts.begin()->first);
  }

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

  Options<T> m_opts{};
  MenuView m_view{};
  std::unique_ptr<MenuInput<T>> m_m_input;
};


#endif /* MENU_H */
