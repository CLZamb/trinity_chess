#ifndef UI_BOARD_INFO_CONTROLLER_H
#define UI_BOARD_INFO_CONTROLLER_H

#include "ui/graphics/board/decorators/board_decorator.h"
#include "ui/graphics/board/board_view.h"
#include "board_info_model.h"
#include "info_pane.h"

class BoardViewInfoDecorator : public BoardDecorator {
 public:
  BoardViewInfoDecorator(unique_ptr<IUIBoard>&& b, BoardView& bv, BoardModelInfo& i);
  virtual ~BoardViewInfoDecorator();

  void print() override;
  void update() override;

 private:
  BoardModelInfo& p_info;
  InfoPane m_info_pane;
};

#endif /* UI_BOARD_INFO_CONTROLLER_H */
