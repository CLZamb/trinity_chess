#ifndef MENU_H
#define MENU_H

#include "view/headers/menu_view.h"
#include "options.h"
#include <sys/wait.h>
#include <unordered_map>
#include "player/headers/keyboard_input.h"

template <typename T> class Menu {
public:
  Menu() {}

  Menu(const Options<T>& opts) : m_opts(opts), m_view(format_options()) {}

  Menu(const string title, const Options<T>& m_opts) : m_opts(m_opts), m_view(format_options()) {
    m_view.set_title(title);
  }

  virtual ~Menu() {}

  void set_title(const string& s) { m_view.set_title(s); }
  void add_options(const Options<T>& m_opts) { this->m_opts = m_opts; }

  T select_option() { 
    if (!p_input) { return m_opts.get_option(0).opt; }

    int selected = p_input->select_menu_option(m_opts.get_keys());
    return m_opts.get_option(selected).opt; 
  }

  void print() { m_view.print(); }

  void add_input_manager(Input& i) {
    p_input = &i; 
    p_input->update_listener(&m_view);
  }

private:
  list<string>  format_options() {
    list<string> options_formatted;
    for (auto i : m_opts.get_options()) {
      options_formatted.push_back(
          std::to_string(i.second.num) + ". " + i.second.desc
      );
    }

    return options_formatted;
  }

  Input* p_input;
  Options<T> m_opts;
  MenuView m_view;
};

#endif /* MENU_H */
