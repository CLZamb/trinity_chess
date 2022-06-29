#ifndef UI_BOARD_DECORATOR_H
#define UI_BOARD_DECORATOR_H

#include "controller/headers/ui_board.h"
#include <memory>

using std::shared_ptr;

class UiBoardDecorator : public UIBoard {
 public:
  UiBoardDecorator(shared_ptr<UIBoard> b); 
  virtual ~UiBoardDecorator() = default;

  virtual void print();
  virtual void update();

 private:
  shared_ptr<UIBoard> _p_ui_board;
};

#endif /* UI_BOARD_DECORATOR_H */     
