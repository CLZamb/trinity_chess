#include "headers/board_fen.h"
#include "game/headers/string_utils.h"

const unordered_map<char, CastlePermission> BoardFen::m_castle_permision { 
  {'Q', WQCA}, {'K', WKCA}, {'q', BQCA}, {'k', BKCA}, {'-', NO_CASTLING},
};

BoardFen::BoardFen(BoardFenInfo &b, const string fen) {
  parse_fen(fen, b);
  update_fen(b);
}

BoardFen::~BoardFen() {}

void BoardFen::update_fen(BoardFenInfo& board) {
  m_board_fen.clear();
  Piecetype piece{EMPTY};
  int space{0};

  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      piece = board.get_piece_at_square(rank * 8 + file);
      if (piece) {
        add_empty_space(m_board_fen, space);
        m_board_fen += utils::piecetype_to_char(piece);
      } else {
        space++;
      }
    }

    if (rank > 0) {
      add_empty_space(m_board_fen, space);
      m_board_fen += "/";
    }
  }

  add_empty_space(m_board_fen, space);

  m_board_fen += ' ';
  m_board_fen += board.get_side_turn();
  m_board_fen += ' ';
  m_board_fen += board.get_castling_rights_string();
  m_board_fen += ' ';
  m_board_fen += board.get_en_passant_square_string();
  m_board_fen += ' ';
  m_board_fen += board.get_half_moves();
  m_board_fen += ' ';
  m_board_fen += board.get_full_moves();
}

// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
// r3k2r/8/5P2/4p3/8/8/8/R3K2R w KQkq e6 0 1

const string &BoardFen::get_fen() { return m_board_fen; }

void BoardFen::add_empty_space(string& f, int &space) {
  if (space) {
    f += std::to_string(space);
  }
  space = 0;
}

void BoardFen::parse_fen(const string &c_str_fen, BoardFenInfo &board) {
  board.clear();

  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  Piecetype piece;
  const char *fen = c_str_fen.c_str();;

  while (*fen != ' ') {
    piece = utils::get_piecetype_from_char_key(*fen);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
      board.set_piece_at_square(square, piece);

      file++;

    } else if (is_number(*fen)) {
      file += (*fen - '0');

    } else if (*fen == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0) break;

    fen++;
  }

  fen++;
  // Color side = (*fen == 'w') ? WHITE : BLACK;
  fen += 2;

  while (*fen != ' ') {
    board.set_castle_permission(m_castle_permision.at(*fen));
    fen++;
  }
  fen++;

	if(*fen != '-')
	{
		file = *fen - 'a';
    fen++;
		rank = *fen - '1';
    square = static_cast<SquareIndices>(rank * 8 + file);
    board.set_en_passant_square(square);
  }
};

bool BoardFen::is_number(char c) { return c >= '0' && c <= '8'; }
