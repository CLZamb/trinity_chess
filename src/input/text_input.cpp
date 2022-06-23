#include "headers/text_input.h"
#include <iostream>

using std::cin;
using std::cout;

TextInput::TextInput() : m_i_p(*this) {}
TextInput::~TextInput() {}

PlayerInput &TextInput::get_player_input() { return m_i_p; }

// const string ConsoleInput::input_space = "\t\t\t\t";
// const string ConsoleInput::invalid_option_msg = input_space + "invalid option
// try again!\n";
//
// ConsoleInput::ConsoleInput() {}
//
// string ConsoleInput::get_player_string_move() {
//   cout << " >> ";
//   return get_string_input();
// }
//
// int ConsoleInput::get_integer_input() {
//   cout << input_space + " >> ";
//   return atoi(get_string_input().c_str());
// }
//
// string ConsoleInput::get_string_input() {
//   string m_input = "quit";
//   cin >> m_input;
//   has_player_quit(m_input);
//   return m_input;
// }
//
// void ConsoleInput::has_player_quit(const string& s) {
//   if (s == "quit" || s == "close" || s == "exit" || s == "q")
//     exit(EXIT_SUCCESS);
// }
