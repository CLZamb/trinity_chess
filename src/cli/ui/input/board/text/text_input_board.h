#ifndef TEXT_INPUT_BOARD_H
#define TEXT_INPUT_BOARD_H

#include "ui/input/board/board_input.h"
#include "ui/input/input_types/text/text_input.h"

class TextInputBoard : public BoardInput {
 public:
  TextInputBoard();
  virtual ~TextInputBoard();
  void get_input_event() override;
 private:
  TextInput m_text_input;
};

#endif /* TEXT_INPUT_BOARD_H */
