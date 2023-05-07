#ifndef MENU_TEXT_EVENT_HANDLER_H
#define MENU_TEXT_EVENT_HANDLER_H

#include "IMenu_event_handler.h"
#include "menu/menu_window/menu_pane.h"
#include "menu/menu_window/options.hpp"
#include "input/text/text_input.h"

template <typename T>
class MenuTextEventHandler : public IMenuEventHandler<T> {
 public:
  MenuTextEventHandler(const std::unique_ptr<Input> &p,
                       MenuPane &v,
                       Options<T> &o)
      : m_pane(v)
      , m_opts(o) {
    p->bind<CommandEventText>(&MenuTextEventHandler::handle_event_string, this);
  }

  const Option<T> &selected_menu_option() override {
    return m_opts.at(m_opt_info.m_key);
  }

  void options_added() override {}

  bool has_events() override {
    m_pane.set_error(m_opt_info.is_valid_option
                         ? ""
                         : "invalid input " + m_opt_info.m_string_input);

    return !m_opt_info.is_valid_option;
  }

  void handle_event_string(CommandEventText &e) {
    std::string m_string_input = e.get_text();

    m_opt_info.m_key = get_option_key(m_string_input);
    m_opt_info.is_valid_option = m_opts.check_key_option(m_opt_info.m_key);
    m_opt_info.m_string_input = m_string_input;
  }

  int get_option_key(const std::string &m_str_input) {
    return is_number(m_str_input) ? atoi(m_str_input.c_str())
                                  : m_opts.get_key_at(m_str_input);
  }

  bool is_number(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
                           return !std::isdigit(c);
                         }) == s.end();
  }

 private:
  struct option_info {
    bool is_valid_option{false};
    int m_key;
    std::string m_string_input;
  };

  option_info m_opt_info;
  bool completed{false};
  MenuPane &m_pane;
  Options<T> &m_opts;
};

#endif /* MENU_TEXT_EVENT_HANDLER_H */
