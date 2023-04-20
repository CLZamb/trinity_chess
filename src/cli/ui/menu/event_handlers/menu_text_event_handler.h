#ifndef MENU_TEXT_EVENT_HANDLER_H
#define MENU_TEXT_EVENT_HANDLER_H

#include "IMenu_event_handler.h"
#include "ui/input/command_event.h"
#include "ui/input/text/text_input.h"
#include "ui/menu/menu_pane.hpp"
#include "ui/menu/options.hpp"

template<typename T>
class MenuTextEventHandler : public IMenuEventHandler<T> {
public:
  MenuTextEventHandler(std::shared_ptr<TextInput> p, MenuPane& v, Options<T> &o) :
  m_pane(v), 
  m_opts(o) {
    p->bind(TextInput::STRING, &MenuTextEventHandler::handle_event_string, this);
  }

  virtual ~MenuTextEventHandler() = default;

  const Option<T>& selected_menu_option() override {
    return m_opts.at(m_key);
  }

  void options_added() override {}

  bool has_events() override {
    return !m_opts.check_valid_option(m_key);
  }

  void handle_event_string(CommandEvent& e) {
    m_key = atoi(e.get_string().c_str());
  }

private:
  int m_key;
  bool completed{false};
  MenuPane& m_pane;
  Options<T>& m_opts;
};

#endif /* MENU_TEXT_EVENT_HANDLER_H */
