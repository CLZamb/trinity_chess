#ifndef UI_BOARD_CONTROLLER_H
#define UI_BOARD_CONTROLLER_H

#include "ui/graphics/board/board_view.h"
#include "board_model.hpp"
#include "ui/graphics/board/decorators/IUi_board.h"

class BoardController : public IUIBoard {
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
