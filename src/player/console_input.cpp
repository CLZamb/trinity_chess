#include "headers/console_input.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;

ConsoleInput::ConsoleInput() {
  m_event.set_type(InputEvent::None);
}

void ConsoleInput::update_turn(const PlayerInfo& info) { m_player_info = info; }

const string &ConsoleInput::get_player_string_move() {
  if (m_player_info.type == GameTurn::Human) 
    get_human_input(m_input);
  else
    get_cpu_input(m_input);

  return m_input;
}

int ConsoleInput::select_menu_option(const vector<int>& opts) {
  if (opts.size() == 0)  return 0;

  int key = -1;
  bool valid_option = false;
  m_event.set_type(InputEvent::None);

  while (!valid_option) {
    key = get_integer_input();
    valid_option = is_valid_option(opts, key);

    if (!valid_option) {
      notify_input_event();
      cout << invalid_option_msg;
    }
  }

  return key;
}

int ConsoleInput::get_integer_input() {
  cout << input_space + " >> ";
  cin >> m_input;
  has_player_quit(m_input);
  return atoi(m_input.c_str());
}

void ConsoleInput::get_human_input(string& input) {
  cout << "\n >> ";
  getline(cin, input);
  cout << "\n";

  has_player_quit(input);
}

void ConsoleInput::get_cpu_input(string& input) {
  return get_human_input(input);
}

void ConsoleInput::has_player_quit(const string& s) {
  if( s == "quit" || s == "close" || s == "exit") exit(EXIT_SUCCESS);
}

void ConsoleInput::notify_input_event() {
  if (p_observer) p_observer->handle_input_event(m_event);
}

void ConsoleInput::update_listener(InputObserver *observer) {
  p_observer = observer;
  notify_input_event();
}

bool ConsoleInput::is_valid_option(const vector<int> options, const int &option) {
  return std::find(options.begin(), options.end(), option) != options.end();
}
