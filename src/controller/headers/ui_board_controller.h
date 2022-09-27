#ifndef UI_BOARD_CONTROLLER_H
#define UI_BOARD_CONTROLLER_H

#include "board/headers/board_fen.h"
#include "view/headers/board_view.h"
#include "controller/headers/ui_board.h"
#include <memory>

class UiBoardController : public UIBoard {
public:
  UiBoardController(BoardView& v, BoardFen& i);
  virtual ~UiBoardController();

  void print() override;
  void update() override;

private:
  BoardView& p_view;
  BoardFen& p_board_fen;
};

#endif /* UI_BOARD_CONTROLLER_H */
