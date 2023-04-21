#include "menu_pane.h"

MenuPane::MenuPane() : Pane(Kmenu_pane_size) {
  add_section(m_top_section, 1);
  add_section(m_title_section, 1);
  add_section(m_options_section, 1);
  add_section(m_error_section,1);
  add_section(m_bottom_section, 1);

  get_section(m_top_section)->set_drawing_at_index(MenuDrawings::menu_top.data(), 0);
  get_section(m_bottom_section)->set_drawing_at_index(MenuDrawings::menu_bottom.data(), 0);
  set_error("");
}

MenuPane::MenuPane(list<string> l_s) : MenuPane() {
  m_l_options = l_s;
  add_options_to_options_section();
}

MenuPane::MenuPane(string title, list<string> ls) : MenuPane(ls) {
  set_title(title);
}

void MenuPane::set_title(string title/* "" */) {
  set_content_at_section(m_title_section, {left_margin(title) + right_margin(title, false)});
}

void MenuPane::set_options(list<string> l_s) {
  m_l_options = l_s;
  add_options_to_options_section();
}

void MenuPane::set_error(string error) {
  set_content_at_section(m_error_section, {left_margin(error) + right_margin(error, false)});
}

void MenuPane::selected_option(const int &i) {
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

void MenuPane::add_options_to_options_section() {
  string s = format_options(m_l_options);
  get_section(m_options_section)->set_drawing_at_index(s, 0);
}


string MenuPane::format_options(list<string> &options) {
  string m_option;
  for (auto o : options) {
    m_option += left_margin(o);
    m_option += right_margin(o);
  }

  m_option += MenuDrawings::empty_row;

  return m_option;
}

string MenuPane::left_margin(const string &s, bool is_selected /* false */) {
  return (
  is_selected ? 
    MenuDrawings::left_margin_selected.data() : MenuDrawings::left_margin.data()
  ) + s;
}

string MenuPane::right_margin(const string &o, bool add_new_line /* true */) {
  string formated_input;
  formated_input += string(get_space_needed(o),' ');
  formated_input += MenuDrawings::right_margin.data();
  if (add_new_line)
    formated_input += "\n";
  return formated_input;
}

size_t MenuPane::get_space_needed(const string &opt) {
  return opt.length() < Kright_space_needed ? Kright_space_needed - opt.length() : 0;
}
