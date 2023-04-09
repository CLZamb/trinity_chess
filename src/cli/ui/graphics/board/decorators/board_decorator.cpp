#include "board_decorator.h"

BoardDecorator::BoardDecorator(unique_ptr<IUIBoard> &&b) : _p_ui_board(std::move(b)) {}

BoardDecorator::~BoardDecorator() {}

void BoardDecorator::print() {
  _p_ui_board->print();
}

void BoardDecorator::update() {
  _p_ui_board->update();
}

