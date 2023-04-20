#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include "menu_drawings.hpp"
#include "ui/components/pane.h"
#include "ui/components/window.h"
#include <list>
#include <string>

using std::string;
using std::list;

class MenuPane : public Pane {
public: 
  MenuPane() {
    add_section(m_top_section, 1);
    add_section(m_title_section, 1);
    add_section(m_options_section, 1);
    add_section(m_bottom_section, 1);

    get_section(m_top_section)->set_drawing_at_index(MenuDrawings::menu_top.data(), 0);
    get_section(m_bottom_section)->set_drawing_at_index(MenuDrawings::menu_bottom.data(), 0);
  }

  MenuPane(list<string> l_s) : MenuPane() {
    m_l_options = l_s;
    add_options_to_options_section();
  }

  MenuPane(string title, list<string> ls) : MenuPane(ls) {
    set_title(title);
  }

  virtual ~MenuPane() {}

  void set_title(string title = "") {
    set_content_at_section(m_title_section, {left_margin(title) + right_margin(title, false)});
  }

  void set_options(list<string> l_s) {
    m_l_options = l_s;
    add_options_to_options_section();
  }

  void selected_option(const int &i) {
    string m_option;
    int index = 1;

    for (const auto &o : m_l_options) {
      m_option += left_margin(o, i == index);
      m_option += right_margin(o);
      index++;
    }

    m_option += MenuDrawings::empty_row;

    set_content_at_section(m_options_section, {m_option});
  }

private:
  void add_options_to_options_section() {
    string s = format_options(m_l_options);
    get_section(m_options_section)->set_drawing_at_index(s, 0);
  }

  string format_options(list<string> &options) {
    string m_option;
    for (auto o : options) {
      m_option += left_margin(o);
      m_option += right_margin(o);
    }

    m_option += MenuDrawings::empty_row;

    return m_option;
  }

  string left_margin(const string &s, bool is_selected = false) {
    return 
    (is_selected ? MenuDrawings::left_margin_selected.data()
    : MenuDrawings::left_margin.data()) 
    + s;
  }

  string right_margin(const string &o, bool add_new_line = true) {
    string formated_input;
    formated_input += string(get_space_needed(o),' ');
    formated_input += MenuDrawings::right_margin.data();
    if (add_new_line)
      formated_input += "\n";
    return formated_input;
  }

  size_t get_space_needed(const string &opt) {
    return opt.length() < right_space_needed ? right_space_needed - opt.length() : 0;
  }

  static const size_t right_space_needed{50};
  list<string> m_l_options{""};
  const string m_top_section = "top";
  const string m_title_section = "title";
  const string m_options_section = "options";
  const string m_bottom_section = "bottom";
  const string m_select_signal = ">>";
};

#endif /* MENU_VIEW_H */