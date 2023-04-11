#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/fen/fen_model.hpp"
#include "game/players/player_position.h"
#include "ui/graphics/components/window.h"
#include "ui/input/board/board_input.h"
#include "ui/input/input_types/input_types.h"
#include <memory>

using std::unique_ptr;

class BoardView : public Window  {
 public:
  BoardView(BoardPane &b);
  virtual ~BoardView();

  void update();
  void print();

  // void add_left_pane(std::unique_ptr<BoardDecorator> &&pane);
  // void add_right_pane(std::unique_ptr<BoardDecorator> &&pane);
  unique_ptr<IUiPaneComponent> &&get_pane_components();

 private:
  // void add_pane_component(std::unique_ptr<BoardDecorator> &&pane);

  // unique_ptr<IUiPaneComponent> p_board_panes;
  BoardPane& m_board_pane;
  const unique_ptr<BoardInput> p_board_input;
};

#endif /* BOARD_VIEW_H */
