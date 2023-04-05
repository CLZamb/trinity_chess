#ifndef MENU_INPUT_H
#define MENU_INPUT_H

#include "ui/graphics/menu/option.h"

using std::string;

template<typename T>
class MenuInput {
 public:
  virtual ~MenuInput() {}
  virtual const Option<T>& select_menu_option() = 0;
};

#endif /* MENU_INPUT_H */
