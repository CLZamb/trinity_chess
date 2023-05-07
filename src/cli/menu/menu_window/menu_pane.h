#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <list>
#include <string>

#include "menu_drawings.hpp"
#include "ui_components/pane.h"
#include "ui_components/window.h"

class MenuPane : public Pane {
 public:
  MenuPane();
  explicit MenuPane(std::list<std::string> l_s);
  MenuPane(std::string title, std::list<std::string> ls);

  void set_title(std::string title = "");
  void set_options(std::list<std::string> l_s);
  void set_option(const std::string &);
  void selected_option(const int &i);
  void set_error(std::string error);

 private:
  void add_options_to_options_section();
  std::string format_options(std::list<std::string> &options);
  std::string left_margin(bool is_selected = false);
  std::string right_margin(const std::string &option, bool add_new_line = true);
  size_t get_space_needed(const std::string &opt);

  static const size_t Kright_space_needed{50};
  static const size_t Kmenu_pane_size{4};
  std::list<std::string> m_list_options{""};
  const std::string m_top_section = "top";
  const std::string m_title_section = "title";
  const std::string m_options_section = "options";
  const std::string m_error_section = "error";
  const std::string m_bottom_section = "bottom";
  const std::string m_select_signal = ">>";
};

#endif /* MENU_VIEW_H */
