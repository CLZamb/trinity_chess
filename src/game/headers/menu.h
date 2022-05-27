#ifndef MENU_H
#define MENU_H

#include "graphics/headers/view.h"
#include "options.h"
#include "player/headers/player.h"

template<typename T>
class Menu {
public:
  Menu() {}
  Menu(Options<T> opts) : opts(opts) , view(MessageView(&msg)) {}
  virtual ~Menu() {}
  void print_menu()  {
    view.print();
  }
  
  T select_option() {
    return opts.select_option();
  }
  
  void print_play_or_quit() {
    print(msg.get_play_or_quit());
  }

  void print_players_options() {
    print(msg.get_players_options());
  }


private:
  void print(MessageState* state) {
    msg.set_message(state);
    view.print();
  }

  Options<T> opts;
  Messages msg;
  MessageView view;
};

#endif /* MENU_H */ 
