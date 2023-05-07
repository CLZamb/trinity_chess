#ifndef MENU_EVENT_HANDLER_H
#define MENU_EVENT_HANDLER_H

#include "menu/menu_window/option.h"

template<typename T>
class IMenuEventHandler {
public:
  virtual const Option<T>& selected_menu_option() = 0;
  virtual bool has_events() = 0;
  virtual void options_added() = 0;
};

#endif /* MENU_EVENT_HANDLER_H */
