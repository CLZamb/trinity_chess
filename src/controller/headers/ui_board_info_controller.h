#ifndef UI_BOARD_INFO_CONTROLLER_H
#define UI_BOARD_INFO_CONTROLLER_H

#include "model/headers/board_info.h"
#include "view/headers/info_pane.h"
#include "controller/headers/ui_board_decorator.h"
#include <memory>

class UiBoardInfoController : public UiBoardDecorator {
 public:
  UiBoardInfoController(shared_ptr<UIBoard> b, BoardInfo& i, InfoPane& p);
  virtual ~UiBoardInfoController();

  void print() override;
  void update() override;

  std::shared_ptr<BoardInfo> p_info;
  std::shared_ptr<InfoPane> p_info_pane;
};


#endif /* UI_BOARD_INFO_CONTROLLER_H */
