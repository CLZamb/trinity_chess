#ifndef MENU_H
#define MENU_H

#include "ui/input/menu/menu_input_builder.h" 
#include "ui/graphics/menu/menu_view.hpp"

template <typename T = string> 
class Menu {
public:
  Menu(InputType input_type) :
    p_input(m_menu_input_builder.get_new_menu_input(input_type, m_view, m_opts)) {}

  Menu(InputType input_type, const string title, const Options<T> &opts) : 
    m_opts(opts),
    m_view(title, format_options()),
    p_input(m_menu_input_builder.get_new_menu_input(input_type, m_view, m_opts)) {
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
  MenuView m_view;
  const std::shared_ptr<MenuInput<T>> p_input;
  MenuInputBuilder m_menu_input_builder;
};

#endif /* MENU_H */
