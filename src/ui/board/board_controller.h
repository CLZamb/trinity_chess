#ifndef UI_BOARD_CONTROLLER_H
#define UI_BOARD_CONTROLLER_H

#include "board/board_fen.h"
#include "ui/board/board_view.h"
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
