#ifndef KEYBOARD_INPUT_MENU_H
#define KEYBOARD_INPUT_MENU_H

#include "game/headers/options.h"
#include "input/headers/keyboard_base.h"
#include "view/headers/menu_view.h"
#include "input/headers/input_type.h"

template<typename T>
class KeyboardInputMenu : public MenuInput<T>{
 public:
  KeyboardInputMenu(KeyboardBase &k, MenuView& v, const Options<T> &o) : 
    m_k_input(k), m_view(v), m_opts(o) {
      p_selection_begin  = o.begin();
      p_selection_back   = --o.crbegin().base();
      p_selection_option = p_selection_begin;
      m_view.selected_option(p_selection_option->first);
    }

  virtual ~KeyboardInputMenu() {}
  
  const Option<T>& select_menu_option() override { 
    p_selection_option = m_opts.cbegin();
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
        if(p_selection_option != p_selection_begin)
          p_selection_option--;
        break;
      case InputKeys::DOWN:
      case InputKeys::S:
        if(p_selection_option != p_selection_back)
          p_selection_option++;
        break;
      default:
        break;
    }
  }

  KeyboardBase& m_k_input;
  MenuView& m_view;
  const Options<T>& m_opts;
  const string key_not_supported = "key not supported\n";
  typename Options<T>::const_iterator  p_selection_option;
  typename Options<T>::const_iterator  p_selection_begin;
  typename Options<T>::const_iterator  p_selection_back;
};


#endif /* KEYBOARD_INPUT_MENU_H */
