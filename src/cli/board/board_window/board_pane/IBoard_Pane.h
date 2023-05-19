#ifndef IBOARD_PANE_H
#define IBOARD_PANE_H

#include <string>

class IBoardPane {
public:
  virtual bool is_string_move_ready() = 0;
  virtual std::string get_move_as_string() = 0;
};

#endif /* IBOARD_PANE_H */
