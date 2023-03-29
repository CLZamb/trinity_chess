#include "board_info_controller.h"

UiBoardInfoController::UiBoardInfoController(
  shared_ptr<UIBoard> b, InfoPane& p, BoardModelInfo& i) :
  BoardDecorator(b), p_info(i), p_info_pane(p) {}

UiBoardInfoController::~UiBoardInfoController() {}

void UiBoardInfoController::print() { 
  p_info_pane.update_game_info(p_info.get_info());
  BoardDecorator::print();
}

void UiBoardInfoController::update() {
  p_info_pane.update_moves(p_info.get_moves());
  p_info_pane.update_captures(p_info.get_captures());
  BoardDecorator::update();
}
