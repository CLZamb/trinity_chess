#ifndef MENU_H
#define MENU_H

#include "view/headers/menu_view.h"
#include "options.h"
#include "player/headers/player.h"
#include <unordered_map>

template <typename T> class Menu {
public:
  Menu() {}

  Menu(Options<T> opts) : opts(opts), view(format_options()) {}

  virtual ~Menu() {}

  void set_title(string s) { view.set_title(s); }

  T select_option() { return opts.select_option(); }

  void print() { view.print(); }

private:

  list<string>  format_options() {
    list<string> options_formatted;
    for (auto i : opts.get_options()) {
      options_formatted.push_front(
          std::to_string(i.second.num) + ". " + i.second.desc
      );
    }

    return options_formatted;
  }

  Options<T> opts;
  MenuView<T> view;
};

#endif /* MENU_H */
