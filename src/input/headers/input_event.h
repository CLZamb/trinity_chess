#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "board/headers/defs.h"
#include <string>

using std::string;

struct InputKeys{
  enum Key {
    NONE      = 0,
    ARROW_KEY = 27,
    UP        = 'A',
    DOWN      = 'B',
    RIGHT     = 'C',
    LEFT      = 'D',
    ENTER     = 10,
    quit      = 'q',
    Quit      = 'Q',
    SELECTED  = 128,
    LEFT_BRACKET  = '[',
  };
};

class InputEvent {
 public:
  enum Type {
    InvalidType = 0,
    None = 1,
    IntInput,
    StringInput,
    KeyPressed, 
    KeyboardSetup,
  };

  InputEvent();
  void set_type(Type t);
  Type get_type() const;

  void set_pressed_key(InputKeys::Key t);
  InputKeys::Key get_pressed_key() const ;

  void set_int_input(const int &i);
  int get_int_input() const;

  void set_string_input(const string &i);
  const string &get_string_input() const;

 private:
    Type m_type;
    InputKeys::Key m_key;
    int m_int_input;
    string m_string_input = "quit";
};

#endif /* INPUT_EVENT_H */

