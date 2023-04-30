#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include "menu_drawings.hpp"
#include "ui_components/pane.h"
#include "ui_components/window.h"
#include <list>
#include <string>

class MenuPane : public Pane {
public: 
  MenuPane();
  explicit MenuPane(std::list<string> l_s);
  MenuPane(string title, std::list<string> ls);
  virtual ~MenuPane() = default;

  void set_title(string title = "");
  void set_options(std::list<string> l_s);
  void set_option(const string&);
  void selected_option(const int &i);
  void set_error(string error);

private:
  void add_options_to_options_section();
  string format_options(std::list<string> &options);
  string left_margin(bool is_selected = false);
  string right_margin(const string &o, bool add_new_line = true);
  size_t get_space_needed(const string &opt);

  static const size_t Kright_space_needed{50};
  static const size_t Kmenu_pane_size{4};
  std::list<string> m_l_options{""};
  const string m_top_section = "top";
  const string m_title_section = "title";
  const string m_options_section = "options";
  const string m_error_section = "error";
  const string m_bottom_section = "bottom";
  const string m_select_signal = ">>";
  
};

#endif /* MENU_VIEW_H */
