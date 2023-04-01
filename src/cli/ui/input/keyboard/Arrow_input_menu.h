#ifndef KEYBOARD_INPUT_MENU_H
#define KEYBOARD_INPUT_MENU_H

#include "options.hpp"
#include "menu_view.hpp"
#include "keyboard_base.h"
#include "input_type.h"

template<typename T>
class ArrowInputMenu : public MenuInput<T>{
 public:
  ArrowInputMenu(KeyboardBase &k, MenuView& v, Options<T> &o) :
    m_k_input(k), m_view(v), m_opts(o) {
      m_view.selected_option(m_opts.begin()->first);
    }

  virtual ~ArrowInputMenu() {}

  const Option<T>& select_menu_option() override { 
    p_selection_option = m_opts.begin();
    bool selected = false;

    while (!selected) {
      switch (InputKeys::Key key = m_k_input.read_key(); key) {
        case InputKeys::ARROW_KEY:
          key = m_k_input.read_arrow_key();
          [[fallthrough]];
        case InputKeys::W:
        case InputKeys::S:
          handle_arrow_key(key);
          m_view.selected_option(p_selection_option->first);
          m_view.print();
          break;
        case InputKeys::ENTER:
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
  void handle_arrow_key(InputKeys::Key k) {
    switch (k) {
      case InputKeys::UP:
      case InputKeys::W:
        if(p_selection_option != m_opts.begin())
          --p_selection_option;
        break;
      case InputKeys::DOWN:
      case InputKeys::S:
        if(p_selection_option != (--m_opts.end()))
          ++p_selection_option;
        break;
      default:
        break;
    }
  }

  typename Options<T>::iterator p_selection_option;
  KeyboardBase& m_k_input;
  MenuView& m_view;
  Options<T>& m_opts;
  const string key_not_supported = "key not supported\n";
};


#endif /* KEYBOARD_INPUT_MENU_H */
