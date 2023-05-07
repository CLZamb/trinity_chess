#include "menu_pane.h"

using std::string;
namespace MD = MenuDrawings;

MenuPane::MenuPane()
    : Pane(Kmenu_pane_size) {
  add_section(m_top_section, 1);
  add_section(m_title_section, 1);
  add_section(m_options_section, 1);
  add_section(m_error_section, 1);
  add_section(m_bottom_section, 1);

  get_section(m_top_section)->set_drawing_at_index(MD::menu_top.data(), 0);
  get_section(m_bottom_section)
      ->set_drawing_at_index(MD::menu_bottom.data(), 0);
  set_error("");
}

MenuPane::MenuPane(std::list<string> l_s)
    : MenuPane() {
  m_list_options = l_s;
  add_options_to_options_section();
}

MenuPane::MenuPane(string title, std::list<string> ls)
    : MenuPane(ls) {
  set_title(title);
}

void MenuPane::set_title(string title /* "" */) {
  set_content_at_section(m_title_section,
                         {left_margin() + title + right_margin(title, false)});
}

void MenuPane::set_options(std::list<string> l_s) {
  m_list_options = l_s;
  add_options_to_options_section();
}

void MenuPane::set_option(const string &s) {
  m_list_options.push_back(s);
  add_options_to_options_section();
}

void MenuPane::set_error(string error) {
  set_content_at_section(m_error_section,
                         {left_margin() + error + right_margin(error, false)});
}

void MenuPane::selected_option(const int &i) {
  string m_option;
  int index = 1;

  for (const auto &o : m_list_options) {
    m_option += left_margin(i == index);
    m_option += o;
    m_option += right_margin(o);
    index++;
  }

  m_option += MD::empty_row;

  set_content_at_section(m_options_section, {m_option});
}

void MenuPane::add_options_to_options_section() {
  string s = format_options(m_list_options);
  get_section(m_options_section)->set_drawing_at_index(s, 0);
}

string MenuPane::format_options(std::list<string> &options) {
  string m_option;
  for (auto o : options) {
    m_option += left_margin();
    m_option += o;
    m_option += right_margin(o);
  }

  m_option += MD::empty_row;

  return m_option;
}

string MenuPane::left_margin(bool is_selected /* false */) {
  return (is_selected ? MD::left_margin_selected.data()
                      : MD::left_margin.data());
}

string MenuPane::right_margin(const string &option,
                              bool add_new_line /* true */) {
  string ftm_line;
  ftm_line += string(get_space_needed(option), ' ');
  ftm_line += MD::right_margin.data();
  if (add_new_line) { ftm_line += "\n"; }
  return ftm_line;
}

size_t MenuPane::get_space_needed(const string &opt) {
  return opt.length() < Kright_space_needed ? Kright_space_needed - opt.length()
                                            : 0;
}
