#include "headers/board.h"
#include "game/headers/move.hpp"

Board::Board() {}

bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) { m_turn_info = turn; }

bool Board::is_legal_move(Move &m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (!piece || !check_piece_belongs_to_player(piece))
    return false;

  if (captured && is_captured_piece_in_same_color(piece, captured))
    return false;

  if (is_king_piece(piece) && is_square_attacked(Move_Utils::get_to(m))) return false;

  return m_pieces[piece]->is_legal_move(m, m_board_bitboard);
}

bool Board::is_captured_piece_in_same_color(const Piecetype &piece,
                                            const Piecetype &captured) {
  return utils::check::get_color_piece(piece) ==
         utils::check::get_color_piece(captured);
}

bool Board::is_square_attacked(const SquareIndices &to) {
  Color c = m_turn_info.color == WHITE ? BLACK : WHITE;
  vector<size_t> opposite_pieces_locations = m_board_bitboard.get_all_locations_at_side(c);
  Move m;
  SquareIndices from;
  for (const size_t& i: opposite_pieces_locations) {
    from = static_cast<SquareIndices>(i);
    m = Move_Utils::make_move(from, static_cast<unsigned int>(to), m_squares[i].get_piece());
    if (!is_king_piece(m_squares[i].get_piece()))
      if (m_pieces[m_squares[i].get_piece()]->is_legal_move(m, m_board_bitboard)) { return true; }
  }
  return false;
}

bool Board::check_piece_belongs_to_player(const Piecetype &pc) {
  return utils::check::get_color_piece(pc) == m_turn_info.color;
}

bool Board::is_king_piece(const Piecetype& pct) {
  return (pct == wK) || (pct == bK);
}

void Board::make_move(Move mv) {
  m_board_bitboard.move(mv);
  move_piece_to_square(mv);
}

void Board::move_piece_to_square(const Move &mv) {
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  m_squares.do_move(from, to);

  if (m_special_move.is_current_move_special_move())
    m_special_move.handle_special_move(mv, m_squares);

  update_half_moves(mv);
  update_full_moves();
}

void Board::update_half_moves(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (piece == bP || piece == wP || captured) {
    half_moves++;
    return;
  }

  half_moves = 0;
}

void Board::update_full_moves() { full_moves++; }

Move Board::string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  Piecetype piece = m_squares[static_cast<unsigned int>(from)].get_piece();
  Piecetype captured = m_squares[static_cast<unsigned int>(to)].get_piece();

  Move_Utils::set_piece(mv, piece);
  Move_Utils::set_capture_piece(mv, captured);

  m_special_move.set_special_move_to_move(mv, m_squares);
  return mv;
}

void Board::clear() {
  m_squares.clear();
  m_board_bitboard.clear();
}

void Board::set_piece_at_square(const SquareIndices &s, const Piecetype &p) {
  m_squares[static_cast<unsigned int>(s)].set_piece(p);
  m_board_bitboard.set_bit_at_player_pieces(utils::check::get_color_piece(p), s);
}

Piecetype Board::get_piece_at_square(const size_t &pos) {
  return m_squares[pos].get_piece();
}

void Board::set_en_passant_square(SquareIndices sq) {
  m_special_move.set_en_passant_square(sq);
}

const SquareIndices &Board::get_en_passant_square() {
  return m_special_move.get_en_passant_square();
}

void Board::set_castle_permission(CastlePermission perm) {
  m_special_move.set_castle_permission(perm);
}

char Board::get_side_turn() {
  return (m_turn_info.color == BLACK) ? 'b' : 'w';
}

string Board::get_en_passant_square_string() {
  string position = string_utils::squareindex_to_str(m_special_move.get_en_passant_square());

  if ("-not a valid position-" == position) return "-";

  return position;
}

string Board::get_castling_rights_string() {
  int castle_perm = m_special_move.get_castle_permission();
  return string_utils::get_permission_str_from_castle_permission(castle_perm);
}

string Board::get_half_moves() {
  return std::to_string(half_moves);
}

string Board::get_full_moves() {
  return std::to_string(full_moves);
}
