#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

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
    W         = 'w',
    A         = 'a',
    S         = 's',
    D         = 'd',
    SELECTED  = 128,
    LEFT_BRACKET  = '[',
  };
};

#endif /* INPUT_EVENT_H */

