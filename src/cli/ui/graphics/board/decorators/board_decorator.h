#ifndef UI_BOARD_DECORATOR_H
#define UI_BOARD_DECORATOR_H

#include "IUi_board.h"
#include "ui/graphics/components/IPane.h"
#include <memory>

using std::unique_ptr;

class BoardDecorator : public IUiPaneComponent {
 public:
  BoardDecorator(unique_ptr<IUiPaneComponent>&& b); 
  virtual ~BoardDecorator();

  virtual void update();
  virtual IPane *get_pane() = 0;

 private:
  unique_ptr<IUiPaneComponent> _p_ui_board;
};

#endif /* UI_BOARD_DECORATOR_H */
