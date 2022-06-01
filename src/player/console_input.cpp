#include "headers/console_input.h"
#include <iostream>

using std::cout;
using std::cout;
using std::cin;

ConsoleInput::ConsoleInput() {}
ConsoleInput::~ConsoleInput() {}

void ConsoleInput::update_turn(const PlayerInfo& info) {
  m_player_info = info;
}

const string& ConsoleInput::get_input() {
  if (m_player_info.get_type() == PlayerInfo::Human) {
    get_human_input();
  } else {
    get_human_input();
  }

  return m_input;
}

void ConsoleInput::get_human_input() {
  cout << "\n" << " >> ";
  getline(cin, m_input);
  cout << "\n";
}

void ConsoleInput::get_cpu_input() {
  get_human_input();
}
