#ifndef MENU_INPUT_HANDLER_H
#define MENU_INPUT_HANDLER_H

#include "game/headers/options.h"
#include "input/headers/input_event.h"
#include "player/headers/input.h"
#include "view/headers/menu_view.h"

template <typename T> 
class MenuInputHandler : public InputObserver  {
 public:
  MenuInputHandler(Input& i, MenuView &v, Options<T> &o) : 
    m_input(i), m_view(v) ,m_opts(o), m_selection(m_opts.get_keys_begin()) {
      m_input.update_listener(this); 
    }

  const T& get_selected_option() {
    m_input.select_menu_option();
    return m_opts.get_option(m_selected).opt;
  }

 private:
  void handle_input_event(const InputEvent& e) override {
    switch(e.get_type()) {
      case InputEvent::KeyPressed:
        handle_key_pressed(e.get_pressed_key());
        break;
      case InputEvent::KeyboardSetup:
        m_view.selected_option(*m_selection);
        break;
      case InputEvent::IntInput:
        handle_int_input(e.get_int_input());
        break;
      default:
        break;
    }
  }

  void handle_key_pressed(const InputKeys::Key key) {
    switch(key) {
      case InputKeys::UP:
        if(m_selection != m_opts.begin())
          m_selection--;
        break;
      case InputKeys::DOWN:
        if(*m_selection != m_opts.back())
          m_selection++;
        break;
      case InputKeys::ENTER:
        m_selected = *m_selection;
        return;
      default:
        std::cout << key_not_supprted;
        return;
    }

    m_view.selected_option(*m_selection);
    m_view.print();
  }

  void handle_int_input(const int &input) {
    if (!m_opts.check_valid_option(input)) {
      std::cout << invalid_option_msg;
      m_input.select_menu_option();
      return;
    }

    m_selected = input;
  }

  Input &m_input;
  MenuView &m_view;
  Options<T> &m_opts;
  vector<int>::const_iterator m_selection;
  int m_selected = 0;
  static const string input_space;
  static const string invalid_option_msg;
  static const string key_not_supprted;
};

template <typename T>
const string MenuInputHandler<T>::input_space = "\t\t\t\t";

template <typename T>
const string MenuInputHandler<T>::invalid_option_msg = input_space + "invalid option try again!\n";

template <typename T>
const string MenuInputHandler<T>::key_not_supprted = "key not supported\n";

#endif /* MENU_INPUT_HANDLER_H */
