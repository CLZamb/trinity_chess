#include  "position.hpp"

Position::Position() : m_occupancies{ZERO} {}

void Position::update_turn(const PlayerInfo &p_info) { m_side_to_move = p_info.color; }

void Position::move(const Move &m) {
  move_piece(MoveUtils::get_piece(m), 
             MoveUtils::get_from(m),
             MoveUtils::get_to(m));
  update_half_moves(m);
  update_full_moves();
}

void Position::undo_move(const Move &m) {
  move_piece(MoveUtils::get_piece(m), 
             MoveUtils::get_to(m),
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
  if (utils::check::is_king_piece(p))
    update_king_position(utils::check::get_color_piece(p), pos);

  m_pieces_pos[pos] = p;

  Color color = utils::check::get_color_piece(p);
  bitUtility::set_bit(&m_pieces_bitboard[p], pos);
  bitUtility::set_bit(&m_occupancies[color], pos);
  bitUtility::set_bit(&m_occupancies[BOTH], pos);
}

void Position::clear_piece_at_square(Piece p, Square pos) {
  m_pieces_pos[pos] = EMPTY;

  Color color = utils::check::get_color_piece(p);
  bitUtility::clear_bit(&m_pieces_bitboard[p], pos);
  bitUtility::clear_bit(&m_occupancies[color], pos);
  bitUtility::clear_bit(&m_occupancies[BOTH], pos);
}

void Position::clear() {
  for (Color c : {WHITE, BLACK}) {
    m_occupancies[c] = BLANK;
  }

  for (PieceType pct : {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING}) {
    m_pieces_bitboard[pct] = BLANK;
  }
}

void Position::clear_square_at_pos(Square sq) {
  clear_piece_at_square(m_pieces_pos[sq], sq);
}

void Position::update_king_position(const Move &mv) {
  Piece pct{MoveUtils::get_piece(mv)};
  if (!utils::check::is_king_piece(pct))
    return;

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

Bitboard Position::operator[](Color c) { return m_occupancies[c]; }
const Piece &Position::get_piece_at_square(Square sq) const { return m_pieces_pos[sq]; }
Square Position::get_king_position(Color c) { return king_position[c]; }
const Square &Position::get_en_passant_square() { return en_passant_pos; }
void Position::set_en_passant_square(Square sq) { en_passant_pos = sq; }
void Position::update_full_moves() { full_moves++; }
int Position::get_half_moves() { return half_moves; }
int Position::get_full_moves() { return half_moves; }
Color Position::side_to_move() const { return m_side_to_move; }
const unsigned int &Position::get_castle_permission() { return castle_perm; }
