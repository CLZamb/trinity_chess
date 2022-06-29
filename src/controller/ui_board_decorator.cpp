#include "controller/headers/ui_board_decorator.h"

UiBoardDecorator::UiBoardDecorator(shared_ptr<UIBoard> b) : _p_ui_board(b) {}

void UiBoardDecorator::print() {
  _p_ui_board->print();
}

void UiBoardDecorator::update() {
  _p_ui_board->update();
}

