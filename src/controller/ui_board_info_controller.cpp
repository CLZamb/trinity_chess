#include "controller/headers/ui_board_info_controller.h"

UiBoardInfoController::UiBoardInfoController(
    shared_ptr<UIBoard> b, BoardInfo& i, InfoPane& p) :
  UiBoardDecorator(b), p_info(&i), p_info_pane(&p) {}


void UiBoardInfoController::print() { 
  p_info_pane->update_game_info(p_info->get_info());
  UiBoardDecorator::print();
}

void UiBoardInfoController::update() {
  p_info_pane->update_moves(p_info->get_moves());
  p_info_pane->update_captures(p_info->get_captures());
  UiBoardDecorator::update();
}
