#include "board_decorator.h"

BoardDecorator::BoardDecorator(shared_ptr<UIBoard> b) : _p_ui_board(b) {}

void BoardDecorator::print() {
  _p_ui_board->print();
}

void BoardDecorator::update() {
  _p_ui_board->update();
}

