#ifndef BOARD_WINDOW_FACTORY_H
#define BOARD_WINDOW_FACTORY_H

#include "board/board.h"
class BoardWindowFactory {
 private:
 public:
  BoardWindowFactory () {}
  virtual ~BoardWindowFactory () {}
  Board create_board_window(Board) {
    BoardConfigInfo m_board_ifno;
    return Board(m_board_ifno);
  }
};

#endif /* BOARD_WINDOW_FACTORY_H */
