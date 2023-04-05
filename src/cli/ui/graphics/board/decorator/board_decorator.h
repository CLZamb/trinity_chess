#ifndef UI_BOARD_DECORATOR_H
#define UI_BOARD_DECORATOR_H

#include "ui/graphics/board/IUi_board.h"
#include <memory>

using std::shared_ptr;

class BoardDecorator : public IUIBoard {
 public:
  BoardDecorator(shared_ptr<IUIBoard> b); 
  virtual ~BoardDecorator();

  virtual void print();
  virtual void update();

 private:
  shared_ptr<IUIBoard> _p_ui_board;
};

#endif /* UI_BOARD_DECORATOR_H */
