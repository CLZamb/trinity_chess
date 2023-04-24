#include "fen_parser.h"

const unordered_map<char, CastlePermission> FenParser::m_castle_permision{
    {'Q', WQCA}, {'K', WKCA}, {'q', BQCA}, {'k', BKCA}, {'-', NO_CASTLING},
};

FenParser::FenParser() {}
FenParser::~FenParser() {}

string FenParser::fen(Position& position) {
  string fen{""};
  Piece piece{EMPTY};
  int space{0};

  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file <= 7; file++) {
      position.get_piece_at_square(static_cast<Square>(rank * 8 + file));
      if (piece) {
        add_empty_space(fen, space);
        fen += utils::piecetype_to_char(piece);
      } else {
        space++;
      }
    }

    if (rank > 0) {
      add_empty_space(fen, space);
      fen += "/";
    }
  }

  add_empty_space(fen, space);

  fen += ' ';
  fen += get_side_turn(position.side_to_move());
  fen += ' ';
  fen += get_castling_rights_string(position.get_castle_permission());
  fen += ' ';
  fen += get_en_passant_square_string(position.get_en_passant_square());
  fen += ' ';
  fen += std::to_string(position.get_half_moves());
  fen += ' ';
  fen += std::to_string(position.get_full_moves());

  return fen;
}

void FenParser::add_empty_space(string &f, int &space) {
  if (space) {
    f += std::to_string(space);
  }
  space = 0;
}

void FenParser::parse_fen(const string &c_str_fen, Position& position) {
  position.clear();

  int square = A1, rank = 7, file = 0;
  Piece piece;
  const char *fen = c_str_fen.c_str();

  while (*fen != ' ') {
    piece = utils::get_piecetype_from_char_key(*fen);
    if (piece) {
      square = rank * 8 + file;
      position.set_piece_at_square(piece, static_cast<Square>(square));

      file++;
    } else if (is_number(*fen)) {
      file += (*fen - '0');

    } else if (*fen == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0)
      break;

    fen++;
  }

  fen++;
  fen += 2;

  while (*fen != ' ') {
    position.set_castle_permission(m_castle_permision.at(*fen));
    fen++;
  }
  fen++;

  if (*fen != '-') {
    file = *fen - 'a';
    fen++;
    rank = *fen - '1';
    square = rank * 8 + file;
    position.set_en_passant_square(static_cast<Square>(square));
  }
};

bool FenParser::is_number(char c) { return c >= '0' && c <= '8'; }

string FenParser::get_castling_rights_string(unsigned int castle_perm) {
  return string_utils::get_permission_str_from_castle_permission(castle_perm);
}

char FenParser::get_side_turn(const Color& c) {
  return (c == BLACK) ? 'b' : 'w';
}

string FenParser::get_en_passant_square_string(const Square en_passant_sq) {
  string en_passant =
    string_utils::squareindex_to_str(en_passant_sq);

  if ("-not a valid position-" == en_passant)
    return "-";

  return en_passant;
}
