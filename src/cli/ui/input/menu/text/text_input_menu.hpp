#ifndef TEXT_INPUT_MENU_HPP
#define TEXT_INPUT_MENU_HPP

#include "ui/input/input_types/text/text_input.h"
#include "ui/input/menu/menu_input.h"
#include "ui/graphics/menu/options.hpp"
#include "ui/graphics/menu/menu_view.hpp"

template<typename T>
class TextInputMenu : public MenuInput<T> {
 public:
  TextInputMenu (MenuView& v, Options<T> &o) : m_view(v), m_opts(o) {}
  virtual ~TextInputMenu () {}

  const Option<T>& select_menu_option() {
    int key = m_opts.begin()->first;
    bool is_valid = false;

    while (!is_valid) {
      key = m_text_input.get_integer_input();
      is_valid = m_opts.check_valid_option(key);

      if (!is_valid) {
        m_view.print();
        std::cout << invalid_option_msg;
      }
    }
    return m_opts.at(key);
  }

 private:
  const string invalid_option_msg = "\t\t\t\tinvalid option try again!\n";
  TextInput m_text_input;
  MenuView& m_view;
  Options<T>& m_opts;
};

#endif /* TEXT_INPUT_MENU_HPP */
