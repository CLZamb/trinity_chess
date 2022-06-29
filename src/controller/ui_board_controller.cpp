#include "controller/headers/ui_board_controller.h"

UiBoardController::UiBoardController(BoardView &v, BoardFen &f)
    : p_view(&v), p_board_fen(&f) {}

UiBoardController::~UiBoardController() {}

void UiBoardController::print() { p_view->print(); }

void UiBoardController::update() {
  p_view->parser_fen(p_board_fen->get_fen());
}
