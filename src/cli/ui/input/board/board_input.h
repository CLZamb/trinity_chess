#ifndef BOARD_INPUT_H
#define BOARD_INPUT_H

#include <string>

class BoardInput {
 public:
  virtual std::string get_next_string_move() = 0;
};

#endif /* BOARD_INPUT_H */
