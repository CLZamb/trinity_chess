#ifndef KEYBOARD_KEY_H
#define KEYBOARD_KEY_H

struct Keyboard {
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
    W         = 'w',
    A         = 'a',
    S         = 's',
    D         = 'd',
    SELECTED  = 128,
    LEFT_BRACKET  = '[',
  };
};

#endif // KEYBOARD_KEY_H
