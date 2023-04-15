#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "ui/input/input_types/input_types.h"
class BoardConfig {
public:
  BoardConfig();
  virtual ~BoardConfig();
  InputType get_input_type() const;
  void set_input_type(InputType i);

private:
  InputType m_input_type {Text};
};

#endif /* PLAYER_CONFIG_H */
