#ifndef TEXT_INPUT_MENU_H
#define TEXT_INPUT_MENU_H

#include "input/headers/input_type.h"
#include "input/headers/text_input_base.h"
#include "view/headers/board_view.h"
#include "game/headers/options.h"

template<typename T>
class TextInputMenu : public MenuInput<T> {
 public:
  TextInputMenu (TextInputBase &k, MenuView& v, Options<T> &o) :
    m_text_input(k), m_view(v), m_opts(o) {}
  virtual ~TextInputMenu () {}

  const Option<T>& select_menu_option() {
    int key = m_opts.begin()->first;
    bool is_valid = false;

    while (!is_valid) {
      key = m_text_input.get_integer_input();
      is_valid = m_opts.check_valid_option(key);

      if (!is_valid) {
        m_view.print();
        std::cout << m_text_input.invalid_option_msg;
      }
    }

    return m_opts.at(key);
  }

 private:
  TextInputBase &m_text_input;
  MenuView& m_view;
  Options<T>& m_opts;
};

#endif /* TEXT_INPUT_MENU_H */
