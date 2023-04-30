#include "position.h"

Position::Position() {}

Position::~Position() {}

void Position::clear() {
  m_board_representation.clear();
  m_castling_rights.clear();
  m_half_move_clock.clear();
  m_en_passant_pos = SquareNull;
  m_side_to_move = NONE;
}

void Position::update_turn(const Color &color) { m_side_to_move = color; }

void Position::make_move(const Move &move) {
  Piece piece = MoveUtils::get_piece(move);
  Square from = MoveUtils::get_from(move);
  Square to = MoveUtils::get_to(move);

  m_board_representation.move_piece(piece, from, to);
}

void Position::undo_move(const Move &move) {
  Piece piece = MoveUtils::get_piece(move);
  Square from = MoveUtils::get_from(move);
  Square to = MoveUtils::get_to(move);

  m_board_representation.move_piece(piece, to, from);
}

void Position::set_side_to_move(Color c) { m_side_to_move = c; }

char Position::get_side_turn_as_char() {
  return (m_side_to_move == BLACK) ? 'b' : 'w';
}

std::string Position::get_en_passant_square_as_string() {
  std::string en_passant = string_utils::squareindex_to_str(m_en_passant_pos);

  if ("-not a valid position-" == en_passant) {
    return "-";
  }

  return en_passant;
}

const Square &Position::get_en_passant_square() { return m_en_passant_pos; }
void Position::set_en_passant_square(Square sq) { m_en_passant_pos = sq; }
Color Position::get_side_to_move() const { return m_side_to_move; }

void Position::set_halfmoves(int halfmoves) {
  m_half_move_clock.set_halfmoves(halfmoves);
}

void Position::set_fullmoves(int fullmoves) {
  m_half_move_clock.set_fullmoves(fullmoves);
}

std::string Position::get_halfmoves_as_string() {
  return m_half_move_clock.get_halfmoves_as_string();
}

std::string Position::get_fullmoves_as_string() {
  return m_half_move_clock.get_fullmoves_as_string();
}

Square Position::get_king_position(Color c) {
  return m_board_representation.get_king_position(c);
}

const Piece &Position::get_piece_at_square(Square sq) const {
  return m_board_representation.get_piece_at_square(sq);
}

Bitboard Position::get_occupied_side_as_bitboard(Color c) {
  return m_board_representation.get_occupied_side_as_bitboard(c);
}

Bitboard Position::get_occupied_squares_as_bitboard() {
  return m_board_representation.get_occupied_squares_as_bitboard();
}

bool Position::is_occupied_at_square(const Square pos) {
  return m_board_representation.is_occupied_at_square(pos);
}

void Position::set_piece_at_square(Piece p, Square position) {
  return m_board_representation.set_piece_at_square(p, position);
}

void Position::clear_square(Square s) {
  m_board_representation.clear_square(s);
}

void Position::set_castle_permission(const char c) {
  m_castling_rights.set_castle_permission(c);
}

std::string Position::get_castling_rights_as_string() {
  return m_castling_rights.get_castling_rights_as_string();
}

CastlePermission Position::get_castle_permission() {
  return m_castling_rights.get_castle_permission();
}

void Position::remove_castle_permission(const CastlePermission &perm) {
  return m_castling_rights.remove_castle_permission(perm);
}

CastlePermission Position::get_castle_permission(Move &m) {
  return m_castling_rights.get_castle_permission(m);
}
