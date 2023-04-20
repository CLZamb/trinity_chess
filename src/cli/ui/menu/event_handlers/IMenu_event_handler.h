#ifndef MENU_EVENT_HANDLER_H
#define MENU_EVENT_HANDLER_H

#include "ui/menu/option.h"

template<typename T>
class IMenuEventHandler {
public:
  virtual ~IMenuEventHandler() = default;
  virtual const Option<T>& selected_menu_option() = 0;
  virtual bool has_events();
  virtual void options_added();
};

#endif /* MENU_EVENT_HANDLER_H */
