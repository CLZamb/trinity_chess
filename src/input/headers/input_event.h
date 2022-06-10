#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "board/headers/defs.h"
#include <string>

using std::string;

struct InputKeys{
  enum Key {
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
    Menu,
    KeyPressed, 
    StringMove,
    KeyboardSetup,
  };

  InputEvent();
  void set_type(Type t);
  Type get_type() const;

  void set_pressed_key(InputKeys::Key t);
  InputKeys::Key get_pressed_key() const ;

  void set_input(const string &i);
  string get_input() const;

  void set_position(const int &pos);
  int get_position() const;

  int get_previous_position() const;
 private:
    Type m_type;
    InputKeys::Key m_key;
    string m_input;
    int m_pos = A1, m_prev_pos = A1;
    int m_current_selected;
};

#endif /* INPUT_EVENT_H */

