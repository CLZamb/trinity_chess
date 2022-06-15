#include "headers/console_input.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;

const string ConsoleInput::input_space = "\t\t\t\t";

ConsoleInput::ConsoleInput() { 
  m_event.set_event_type(InputEvent::None); 
  m_event.set_type(InputEvent::Text);
}

void ConsoleInput::get_player_string_move() {
  m_event.set_event_type(InputEvent::String);
  cout << ">> ";
  m_event.set_string_input(get_string_input());
  notify_input_event();
}

void ConsoleInput::select_menu_option() {
  m_event.set_event_type(InputEvent::Int);
  m_event.set_int_input(get_integer_input());
  notify_input_event();
}

int ConsoleInput::get_integer_input() {
  cout << input_space + " >> ";
  return atoi(get_string_input().c_str());
}

string ConsoleInput::get_string_input() {
  string m_input = "quit";
  cin >> m_input;
  has_player_quit(m_input);
  return m_input;
}

void ConsoleInput::has_player_quit(const string& s) {
  if (s == "quit" || s == "close" || s == "exit" || s == "q")
    exit(EXIT_SUCCESS);
}

void ConsoleInput::notify_input_event() {
  if (!p_observer) return;

  p_observer->handle_input_event(m_event);
}

void ConsoleInput::update_input_event_listener(InputObserver *observer) {
  if (!observer) return;

  p_observer = observer;
  m_event.set_event_type(InputEvent::Setup);
  notify_input_event();
}

void ConsoleInput::dispatch_event(const InputEvent& event) {
  m_event.set_event_type(event.get_event_type());
  notify_input_event();
}
