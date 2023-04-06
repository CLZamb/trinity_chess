#ifndef UI_BOARD_INFO_CONTROLLER_H
#define UI_BOARD_INFO_CONTROLLER_H

#include "board_model_info.h"
#include "info_pane.h"
#include "ui/graphics/board/decorator/board_decorator.h"

class UiBoardInfoController : public BoardDecorator {
 public:
  UiBoardInfoController(shared_ptr<IUIBoard> b, InfoPane& p, BoardModelInfo& i);
  virtual ~UiBoardInfoController();

  void print() override;
  void update() override;

 private:
  BoardModelInfo& p_info;
  InfoPane& p_info_pane;
};


#endif /* UI_BOARD_INFO_CONTROLLER_H */
