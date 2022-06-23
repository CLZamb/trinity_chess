#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "board/headers/board.h"
#include "input/headers/input_type.h"
#include "model/headers/board_info.h"
#include "input/headers/text_input_base.h"
#include "input/headers/text_input_player.h"

class TextInput : public TextInputBase, public InputType {
 public:
  TextInput();
  virtual ~TextInput();
  PlayerInput &get_player_input() override;

 private:
  bool check_valid_option(vector<int>& keys, const int key) {
    return std::find(keys.begin(), keys.end(), key) != keys.end();
  };

  TextInputPlayer m_i_p;
};

#endif /* CONSOLE_INPUT_H */
