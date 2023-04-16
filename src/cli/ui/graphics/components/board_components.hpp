#ifndef BOARD_COMPONENTS_H
#define BOARD_COMPONENTS_H

#include "ui/graphics/board/panes/board/board_text_pane.h"
#include "ui/graphics/board/panes/info/board_check_info_decorator.h"
#include "ui/graphics/board/panes/info/info_pane.h"
#include "ui/graphics/board/panes/board/board_keyboard_pane.h"
#include "ui/input/board/keyboard/keyboard_input_board.h"
#include "ui/input/board/keyboard/keyboard_input_board_event_handler.hpp"
#include "ui/input/board/text/text_input_board.h"
#include "ui/input/input_types/input_types.h"
#include "ui/graphics/board/panes/info/board_check_info_decorator.h"
#include <memory>

using std::make_shared;
using std::make_unique;

class BoardComponents {
public:
  BoardComponents() {}
  virtual ~BoardComponents() {}

  auto new_board_keyboard_pane(const string &f, shared_ptr<KeyboardInputBoard> p) {
    return make_shared<BoardKeyboardPane>(f, p);
  }

  // auto new_board_keyboard_pane(const string &f, shared_ptr<KeyboardInputBoard> p) {
  //   return make_shared<BoardKeyboardPane>(f, p);
  // }

  shared_ptr<KeyboardInputBoard> new_input_keyboard() {
    return make_unique<KeyboardInputBoard>();
  }

  shared_ptr<TextInputBoard> new_input_text() {
    return make_unique<TextInputBoard>();
  }

  auto new_info_pane(BoardModelInfo& b) {
    return make_shared<InfoPane>(b);
  }

  auto new_info_check_behaviour(BoardCheck& b, BoardModelInfo& m){
    return make_unique<BoardCheckInfoDecorator>(std::move(b.get_behaviour()), m);
  }

  auto new_board_pane(const string& fen, shared_ptr<TextInputBoard> p) {
    return std::make_shared<BoardTextPane>(fen, p);
  }

};




#endif /* BOARD_COMPONENTS_H */
