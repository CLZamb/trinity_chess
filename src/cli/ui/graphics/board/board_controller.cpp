#include "board_controller.h"

BoardController::BoardController(BoardView &v, const BoardFen&f)
  : p_view(v), p_board_fen(f) {
}

BoardController::~BoardController() {}

void BoardController::print() { 
  p_view.print(); 
}

void BoardController::update() {
  p_view.parse_fen(p_board_fen.get_fen());
  p_view.update_board_drawing();
}
