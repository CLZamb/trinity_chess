#ifndef TEXT_INPUT_BOARD_H
#define TEXT_INPUT_BOARD_H

#include "ui/input/board/board_input.h"
#include "ui/input/input_types/text/text_input_base.h"

class TextInputBoard : public BoardInput {
  public:
    TextInputBoard();
    virtual ~TextInputBoard();
    string get_next_string_move() override;
  private:
    TextInputBase m_text_input;
};

#endif /* TEXT_INPUT_BOARD_H */
