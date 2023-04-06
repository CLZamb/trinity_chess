#ifndef KEYBOARD_INPUT_MENU_H
#define KEYBOARD_INPUT_MENU_H

#include "ui/input/input_types/keyboard/keyboard_input.h"
#include "ui/graphics/menu/options.hpp"
#include "ui/graphics/menu/menu_view.hpp"
#include "ui/input/menu/menu_input.h"
#include <iostream>

template<typename T>
class KeyboardInputMenu : public MenuInput<T>{
 public:
  KeyboardInputMenu(MenuView& v, Options<T> &o) :
    m_view(v), 
    m_opts(o) {
    m_view.selected_option(m_opts.begin()->first);
  }

  virtual ~KeyboardInputMenu() {}

  const Option<T>& select_menu_option() override { 
    p_selection_option = m_opts.begin();
    bool selected = false;

    while (!selected) {
      switch (Keyboard::Key key = m_k_input.read_key(); key) {
        case Keyboard::ARROW_KEY:
          key = m_k_input.read_arrow_key();
          [[fallthrough]];
        case Keyboard::W:
        case Keyboard::S:
          handle_arrow_key(key);
          m_view.selected_option(p_selection_option->first);
          m_view.print();
          break;
        case Keyboard::ENTER:
          selected = true;
          break;
        default:
          std::cout << key_not_supported;
          break;
      }
    }
    return p_selection_option->second;
  }

 private:
  void handle_arrow_key(Keyboard::Key k) {
    switch (k) {
      case Keyboard::UP:
      case Keyboard::W:
        if(p_selection_option != m_opts.begin())
          --p_selection_option;
        break;
      case Keyboard::DOWN:
      case Keyboard::S:
        if(p_selection_option != (--m_opts.end()))
          ++p_selection_option;
        break;
      default:
        break;
    }
  }

  typename Options<T>::iterator p_selection_option;
  KeyboardInput m_k_input;
  MenuView& m_view;
  Options<T>& m_opts;
  const string key_not_supported = "key not supported\n";
};


#endif /* KEYBOARD_INPUT_MENU_H */
