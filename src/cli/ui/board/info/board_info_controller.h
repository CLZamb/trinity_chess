#ifndef UI_BOARD_INFO_CONTROLLER_H
#define UI_BOARD_INFO_CONTROLLER_H

#include "board_model_info.h"
#include "info_pane.h"
#include "board_decorator.h"
#include <memory>

class UiBoardInfoController : public BoardDecorator {
 public:
  UiBoardInfoController(shared_ptr<UIBoard> b, InfoPane& p, BoardModelInfo& i);
  virtual ~UiBoardInfoController();

  void print() override;
  void update() override;

  BoardModelInfo& p_info;
  InfoPane& p_info_pane;
};


#endif /* UI_BOARD_INFO_CONTROLLER_H */
