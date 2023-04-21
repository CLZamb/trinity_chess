#ifndef MENU_TEXT_EVENT_HANDLER_H
#define MENU_TEXT_EVENT_HANDLER_H

#include "IMenu_event_handler.h"
#include "ui/input/text/text_input.h"
#include "ui/menu_window/menu_pane.h"
#include "ui/menu_window/options.hpp"

template<typename T>
class MenuTextEventHandler : public IMenuEventHandler<T> {
public:
  MenuTextEventHandler(
    std::shared_ptr<TextInput> p, 
    MenuPane& v, 
    Options<T> &o) : m_pane(v), m_opts(o) {
    p->bind<CommandEventText>(&MenuTextEventHandler::handle_event_string, this);
  }

  virtual ~MenuTextEventHandler() = default;

  const Option<T>& selected_menu_option() override {
    return m_opts.at(m_key);
  }

  void options_added() override {}

  bool has_events() override {
    bool valid_input = m_opts.check_valid_option(m_key);

    m_pane.set_error(valid_input ? "" : "invalid input");

    return !valid_input;
  }

  void handle_event_string(CommandEventText& e) {
    m_key = atoi(e.get_string().c_str());
  }

private:
  int m_key;
  bool completed{false};
  MenuPane& m_pane;
  Options<T>& m_opts;
};

#endif /* MENU_TEXT_EVENT_HANDLER_H */
