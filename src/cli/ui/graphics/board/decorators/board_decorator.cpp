#include "board_decorator.h"

BoardDecorator::BoardDecorator(unique_ptr<IUiPaneComponent> &&b) : _p_ui_board(std::move(b)) {}
BoardDecorator::~BoardDecorator() {}
void BoardDecorator::update() { _p_ui_board->update(); }

