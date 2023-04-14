#ifndef BOARD_DECORATOR_H
#define BOARD_DECORATOR_H

#include "ui/graphics/board/decorators/IUi_board.h"
#include "ui/graphics/components/pane.h"
#include <memory>

using std::shared_ptr;

class BoardDecorator : public IUiPaneComponent {
 public:
  BoardDecorator(shared_ptr<IUiPaneComponent> p) : _component(p) {}
  virtual ~BoardDecorator() {}
  virtual void update() { _component->update(); }

private:
  shared_ptr<IUiPaneComponent> _component;
};

#endif // !BOARD_DECORATOR_H
