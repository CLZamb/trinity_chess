#ifndef UI_BOARD_CONTROLLER_H
#define UI_BOARD_CONTROLLER_H

#include "board/headers/board_fen.h"
#include "model/headers/player_info.h"
#include "view/headers/board_view.h"
#include "controller/headers/ui_board.h"
#include <memory>

class UiBoardController : public UIBoard {
public:
  UiBoardController(BoardView& v, BoardFen& i);
  virtual ~UiBoardController ();

  void print() override;
  void update() override;

private:
  std::shared_ptr<BoardView> p_view;
  std::shared_ptr<BoardFen> p_board_fen;
  PlayerInfo m_player_info;
};

#endif /* UI_BOARD_CONTROLLER_H */
