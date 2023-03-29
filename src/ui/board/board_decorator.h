#ifndef UI_BOARD_DECORATOR_H
#define UI_BOARD_DECORATOR_H

#include "i_ui_board.h"
#include <memory>

using std::shared_ptr;

class BoardDecorator : public UIBoard {
 public:
  BoardDecorator(shared_ptr<UIBoard> b); 
  virtual ~BoardDecorator() = default;

  virtual void print();
  virtual void update();

 private:
  shared_ptr<UIBoard> _p_ui_board;
};

#endif /* UI_BOARD_DECORATOR_H */     
