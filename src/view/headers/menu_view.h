#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <list>
#include <string>
#include "view.h"
#include "graphics/headers/game_drawings.hpp"

using std::string;
using std::list;

template<typename T>
class MenuView : public View {
  public: 
    MenuView(list<string> l_s) : View("Menu") {
      string s = format_options(l_s);

      m_pane.add_section(m_top_section, 1);
      m_pane.add_section(m_title_section, 1);
      m_pane.add_section(m_options_section, 1);
      m_pane.add_section(m_bottom_section, 1);

      m_pane.get_section(m_top_section)->set_content_at_index(MenuDrawings::p_menu_top.data(), 0 );
      m_pane.get_section(m_options_section)->set_content_at_index(s, 0);
      m_pane.get_section(m_bottom_section)->set_content_at_index(MenuDrawings::p_menu_bottom.data(), 0 );

      set_title();

      window_view.add_pane(this, Window::Left_pane);
    }

    void set_title(string title = "") {
      m_pane.set_content_at_section(m_title_section, {add_margins(title)});
    }

 private:
  static const size_t left_space_needed{32};
  static const size_t right_space_needed{46};
  const string m_top_section = "top";
  const string m_title_section = "title";
  const string m_options_section = "options";
  const string m_bottom_section = "bottom";

  string format_options(list<string> &options) {
    string m_option;
    for (auto o : options) {
      m_option += add_margins(o) + (options.back() == o ? "": "\n");
    }
    return m_option;
  }

  string add_margins(const string &opt) {
    auto spaced_needed = right_space_needed - opt.length();
    return 
      MenuDrawings::left_margin.data() + string(left_space_needed,' ') +
      opt +
      string(spaced_needed,' ') + MenuDrawings::right_margin.data();
  }
};
#endif /* MENU_VIEW_H */
