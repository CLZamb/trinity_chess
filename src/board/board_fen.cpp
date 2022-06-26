#include "headers/board_fen.h"

BoardFen::BoardFen() {}
BoardFen::~BoardFen() {}

void BoardFen::set_fen(const string &f) {
  fen = f;
}

const string &BoardFen::get_fen() const {
  return fen;
}
