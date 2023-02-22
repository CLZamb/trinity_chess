#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <list>
#include <string>
#include "view.h"
#include "graphics/headers/game_drawings.hpp"

using std::string;
using std::list;

class MenuView : public View {
  public: 
    MenuView() : MenuView({""}) {}
    MenuView(list<string> l_s) : View("Menu"), m_l_options(l_s) {
      string s = format_options(m_l_options);

      m_pane.add_section(m_top_section, 1);
      m_pane.add_section(m_title_section, 1);
      m_pane.add_section(m_options_section, 1);
      m_pane.add_section(m_bottom_section, 1);

      m_pane.get_section(m_top_section)->set_content_at_index(MenuDrawings::p_menu_top.data(), 0 );
      m_pane.get_section(m_options_section)->set_content_at_index(s, 0);
      m_pane.get_section(m_bottom_section)->set_content_at_index(MenuDrawings::p_menu_bottom.data(), 0 );

      _window.add_pane(this, Window::Left_pane);
    }

    MenuView(string title, list<string> ls) : MenuView(ls) {
      set_title(title);
    }

    virtual ~MenuView() {}

    void set_title(string title = "") {
      m_pane.set_content_at_section(m_title_section, {left_margin(title) + right_margin(title, false)});
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

      m_pane.set_content_at_section(m_options_section, {m_option});
    }

    void draw() override {}

 private:
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
  list<string> m_l_options;
  const string m_top_section = "top";
  const string m_title_section = "title";
  const string m_options_section = "options";
  const string m_bottom_section = "bottom";
  const string m_select_signal = ">>";
};

#endif /* MENU_VIEW_H */
