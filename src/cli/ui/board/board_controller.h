#ifndef UI_BOARD_CONTROLLER_H
#define UI_BOARD_CONTROLLER_H

#include "board_view.h"
#include "board_model.hpp"
#include "i_ui_board.h"

class BoardController : public UIBoard {
public:
  BoardController(BoardView& v, BoardModel& i);
  virtual ~BoardController();

  void print() override;
  void update() override;

private:
  BoardView& p_view;
  BoardModel& p_board_fen;
};

#endif /* UI_BOARD_CONTROLLER_H */
