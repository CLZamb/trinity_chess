#include "position.h"

const unordered_map<char, CastlePermission> Position::m_castle_permision{
    {'Q', WQCA}, {'K', WKCA}, {'q', BQCA}, {'k', BKCA}, {'-', NO_CASTLING},
};

Position::Position() : m_occupancies{ZERO} {}

void Position::update_turn(const Color &color) { m_side_to_move = color; }

void Position::move(const Move &m) {
  move_piece(MoveUtils::get_piece(m), MoveUtils::get_from(m),
             MoveUtils::get_to(m));
  update_half_moves(m);
  update_full_moves();
}

void Position::undo_move(const Move &m) {
  move_piece(MoveUtils::get_piece(m), MoveUtils::get_to(m),
             MoveUtils::get_from(m));
}

void Position::move_piece(const Piece p, const Square from, const Square to) {
  clear_piece_at_square(p, from);
  set_piece_at_square(p, to);
}

bool Position::is_occupied_at_square(const Square pos) {
  return m_occupancies[BOTH] & (ONE << pos);
}

void Position::set_piece_at_square(Piece p, Square pos) {
  if (utils::check::is_king_piece(p)) {
    update_king_position(utils::check::get_color_piece(p), pos);
  }

  m_pieces_pos[pos] = p;

  Color color = utils::check::get_color_piece(p);
  bitUtility::set_bit(&m_occupancies[color], pos);
  bitUtility::set_bit(&m_occupancies[BOTH], pos);
}

void Position::clear_piece_at_square(Piece p, Square pos) {
  m_pieces_pos[pos] = EMPTY;

  Color color = utils::check::get_color_piece(p);
  bitUtility::clear_bit(&m_occupancies[color], pos);
  bitUtility::clear_bit(&m_occupancies[BOTH], pos);
}

void Position::clear() {
  for (Color c : {WHITE, BLACK}) {
    m_occupancies[c] = BLANK;
  }
}

void Position::clear_square_at_pos(Square sq) {
  clear_piece_at_square(m_pieces_pos[sq], sq);
}

void Position::update_king_position(const Move &mv) {
  Piece pct{MoveUtils::get_piece(mv)};
  if (!utils::check::is_king_piece(pct)) {
    return;
  }

  Color piece_color = utils::check::get_color_piece(pct);

  Square pos = MoveUtils::get_to(mv);
  update_king_position(piece_color, pos);
}

void Position::update_half_moves(const Move &m) {
  Piece piece = MoveUtils::get_piece(m);
  Piece captured = MoveUtils::get_captured_piece(m);

  if (utils::check::is_pawn_piece(piece) || captured) {
    half_moves++;
    return;
  }

  half_moves = 0;
}

void Position::update_king_position(Color c, const Square &pos) {
  king_position[c] = pos;
}

void Position::set_castle_permission(CastlePermission perm) {
  castle_perm |= perm;
}

void Position::remove_castle_permission(const CastlePermission &perm) {
  castle_perm ^= perm;
}

CastlePermission Position::get_castle_permission(Move &m) {
  Color side = utils::check::get_color_piece(MoveUtils::get_piece(m));
  CastleSquares to = static_cast<CastleSquares>(MoveUtils::get_to(m));
  return m_castle_permission.at(side).at(to);
}

string Position::fen(Position &position) {
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

void Position::add_empty_space(string &f, int &space) {
  if (space) {
    f += std::to_string(space);
  }
  space = 0;
}

void Position::parse_fen(const string &c_str_fen) {
  clear();

  int square = A1, rank = 7, file = 0;
  Piece piece;
  const char *fen = c_str_fen.c_str();

  while (*fen != ' ') {
    piece = utils::get_piecetype_from_char_key(*fen);
    if (piece) {
      square = rank * 8 + file;
      set_piece_at_square(piece, static_cast<Square>(square));

      file++;
    } else if (is_number(*fen)) {
      file += (*fen - '0');

    } else if (*fen == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0) {
      break;
    }

    fen++;
  }

  fen++;
  fen += 2;

  while (*fen != ' ') {
    set_castle_permission(m_castle_permision.at(*fen));
    fen++;
  }
  fen++;

  if (*fen != '-') {
    file = *fen - 'a';
    fen++;
    rank = *fen - '1';
    square = rank * 8 + file;
    set_en_passant_square(static_cast<Square>(square));
  }
};

bool Position::is_number(char c) { return c >= '0' && c <= '8'; }

string Position::get_castling_rights_string(unsigned int castle_pr) {
  return string_utils::get_permission_str_from_castle_permission(castle_pr);
}

char Position::get_side_turn(const Color &c) {
  return (c == BLACK) ? 'b' : 'w';
}

string Position::get_en_passant_square_string(const Square en_passant_sq) {
  string en_passant = string_utils::squareindex_to_str(en_passant_sq);

  if ("-not a valid position-" == en_passant) {
    return "-";
  }

  return en_passant;
}

Bitboard Position::operator[](Color c) { return m_occupancies[c]; }
const Piece &Position::get_piece_at_square(Square sq) const {
  return m_pieces_pos[sq];
}
Square Position::get_king_position(Color c) { return king_position[c]; }
const Square &Position::get_en_passant_square() { return en_passant_pos; }
void Position::set_en_passant_square(Square sq) { en_passant_pos = sq; }
void Position::update_full_moves() { full_moves++; }
int Position::get_half_moves() { return half_moves; }
int Position::get_full_moves() { return half_moves; }
Color Position::side_to_move() const { return m_side_to_move; }
const unsigned int &Position::get_castle_permission() { return castle_perm; }
