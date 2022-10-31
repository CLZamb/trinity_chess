#include "headers/board.h"
#include "board/headers/defs.h"
#include "board/headers/special_move.h"
#include "board/headers/square.h"
#include "board/headers/utils.h"
#include <algorithm>

Board::Board() {}

bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) { 
  m_turn_info = turn; 
}

bool Board::is_legal_move(Move &m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (!piece || !check_piece_belongs_to_player(piece))
    return false;

  if (captured && is_captured_piece_in_same_color(piece, captured))
    return false;

  // if (is_square_attacked(king)) return false;

  return m_pieces[piece]->is_legal_move(m, m_board_bitboard);
}

bool Board::is_captured_piece_in_same_color(const Piecetype piece, const Piecetype captured) {
  return utils::check::get_color_piece(piece) ==
         utils::check::get_color_piece(captured);
}

bool Board::check_piece_belongs_to_player(const Piecetype pc) {
  return utils::check::get_color_piece(pc) == m_turn_info.color;
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
}

Move Board::string_to_move(const string &m) {
  Move mv = string_utils::to_move(m);
  SquareIndices from = Move_Utils::get_from(mv);
  SquareIndices to = Move_Utils::get_to(mv);

  Piecetype piece = m_squares[from].get_piece();
  Piecetype captured = m_squares[to].get_piece();

  Move_Utils::set_piece(mv, piece);
  Move_Utils::set_capture_piece(mv, captured);

  m_special_move.set_special_move_to_move(mv, m_squares);
  return mv;
}

void Board::clear() {
  m_squares.clear();
  m_board_bitboard.clear();
}

void Board::set_piece_at_square(const SquareIndices& s, const Piecetype& p) {
  m_squares[s].set_piece(p);
  m_board_bitboard.set_bit_at_player_pieces(utils::check::get_color_piece(p), s);
}

Piecetype Board::get_piece_at_square(const int &pos) {
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
