#include "text_input_base.h"

#include <limits>

using std::cin;
using std::cout;
using std::string;

const string TextInputBase::input_space = "\t\t\t\t";

TextInputBase::TextInputBase() {}
TextInputBase::~TextInputBase() {}

string TextInputBase::get_string_input() {
  string m_input = "quit";
  cin >> m_input;
  cin.ignore();   // consume the newline character in the input buffer
  has_player_quit(m_input);
  return m_input;
}

int TextInputBase::get_integer_input() {
  cout << input_space + " >> ";
  return atoi(get_string_input().c_str());
}

void TextInputBase::has_player_quit(const string &s) {
  if (s == "quit" || s == "close" || s == "exit" || s == "q") {
    exit(EXIT_SUCCESS);
  }
}
