#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <list>
#include <string>
#include <memory>
#include "graphics/headers/section.h"
#include "view.h"
#include "graphics/headers/game_drawings.hpp"


using std::make_unique;
using std::string;
using std::list;

template<typename T>
class MenuView : public View {
  public: 
    MenuView(list<string> l_s) : View("Menu") {
      string s = format_line(l_s);
      p_top = make_unique<Section>("top", 1);
      p_title = make_unique<Section>("title", 1);
      p_options = make_unique<Section>("top", 1);
      p_bottom = make_unique<Section>("top", 1);

      m_drawing.add_section(p_top);
      m_drawing.add_section(p_title);
      m_drawing.add_section(p_options);
      m_drawing.add_section(p_bottom);

      p_top->set_content_at_index(MenuDrawings::p_menu_top.data(), 0);
      p_bottom->set_content_at_index(MenuDrawings::p_menu_bottom.data(), 0);
      p_options->set_content({s});

      window_view.add_pane(this, Window::Left_pane);
      set_title();
    }

    void set_title(string title = "") {
      p_title->set_content({add_margins(title)});
    }
 private:
  static const size_t left_space_needed{32};
  static const size_t right_space_needed{46};

  string format_line(list<string> &options) {
    string m_option;
    for (auto o : options) {
      m_option += add_margins(o) + (options.back() == o ? "": "\n");
    }
    return m_option;
  }

  string add_margins(const string &opt) {
    auto spaced_needed = right_space_needed - opt.length();
    return 
      MenuDrawings::left_margin.data() + 
      std::string(left_space_needed,' ') +
      opt +
      std::string(spaced_needed,' ') +
      MenuDrawings::right_margin.data();
  }
  shared_ptr<Section> p_top;
  shared_ptr<Section> p_title;
  shared_ptr<Section> p_options;
  shared_ptr<Section> p_bottom;
};
#endif /* MENU_VIEW_H */
