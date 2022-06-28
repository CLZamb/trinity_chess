#include "headers/board_fen.h"

BoardFen::BoardFen(Squares &s) : m_squares(s) {}
BoardFen::~BoardFen() {}

void BoardFen::set_fen(const string &f) {
  fen = f;
}

const string &BoardFen::get_fen() {
  fen.clear();
  Piecetype pc{EMPTY};
  int space{0};
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      pc = m_squares[rank * 8 + file].get_piece();
      if (pc) {
        add_empty_space(fen, space);
        fen += utils::piecetype_to_char(pc);
      } else {
        space++;
      }
    }
    if (rank > 0) {
      add_empty_space(fen, space);
      fen += "/";
    }
  }

  return fen;
}

void BoardFen::add_empty_space(string& f, int &space) {
  if (space) {
    f += std::to_string(space);
  }
  space = 0;
}
