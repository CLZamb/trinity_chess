#include "headers/board_fen.h"

BoardFen::BoardFen(Squares &s) : m_squares(s) {}
BoardFen::~BoardFen() {}

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

void BoardFen::parse_fen(const string &fen, BoardBitboard& board_bitboard) {
  m_squares.clear();
  board_bitboard.clear();

  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  Piecetype piece;

  for (const char &c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
      m_squares[square].set_piece(piece);
      board_bitboard.set_bit_at_player_pieces(utils::check::get_color_piece(piece), square);

      file++;

    } else if (is_number(c)) {
      file += (c - '0');

    } else if (c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0)
      break;
  }
};

bool BoardFen::is_number(char c) { return c >= '0' && c <= '8'; }
