#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/fen/fen_model.hpp"
#include "game/players/player_position.h"
#include "ui/graphics/board/board_pane.h"
#include "ui/graphics/board/decorators/board_decorator.hpp"
#include "ui/graphics/components/window.h"
#include "ui/input/input_types/input_handler.h"
#include <memory>
#include <list>

class BoardView : public Window  {
 public:
  BoardView();
  virtual ~BoardView();

  void update();
  void print();
  void add_right_pane(shared_ptr<IUiPaneComponent> p);
  void add_left_pane(shared_ptr<IUiPaneComponent> p);
  void add_board_pane(shared_ptr<BoardPane> b) ;
  void add_input_event_handler(shared_ptr<InputHandler> i);
  bool handle_input(KeyCode::Key e, string& callback);
  string get_string_move();
 private:
  // prevent the use of window_add_middle function
  using Window::add_middle_pane; 

  shared_ptr<IUiPaneComponent> p_panes;
  shared_ptr<InputHandler> p_input_handler;
};

#endif /* BOARD_VIEW_H */
