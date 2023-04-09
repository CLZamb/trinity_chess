#ifndef UI_BOARD_DECORATOR_H
#define UI_BOARD_DECORATOR_H

#include "IUi_board.h"
#include <memory>

using std::unique_ptr;

class BoardDecorator : public IUIBoard {
 public:
  BoardDecorator(unique_ptr<IUIBoard>&& b); 
  virtual ~BoardDecorator();

  virtual void print();
  virtual void update();

 private:
  unique_ptr<IUIBoard> _p_ui_board;
};

#endif /* UI_BOARD_DECORATOR_H */
