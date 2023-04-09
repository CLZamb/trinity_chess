#ifndef UI_BOARD_CONTROLLER_H
#define UI_BOARD_CONTROLLER_H

#include "board/fen/fen_model.hpp"
#include "ui/graphics/board/board_view.h"
#include "ui/graphics/board/decorators/IUi_board.h"

class BoardController : public IUIBoard {
public:
  BoardController(BoardView& v, const BoardFen& i);
  virtual ~BoardController();

  void print() override;
  void update() override;

private:
  BoardView& p_view;
  const BoardFen& p_board_fen;
};

#endif /* UI_BOARD_CONTROLLER_H */
