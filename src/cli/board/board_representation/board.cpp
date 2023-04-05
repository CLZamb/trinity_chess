#include "board.h"
#include "utils/string_utils.h"

Board::Board() {}

void Board::make_move(Move mv) {
  m_board_bitboard.move(mv);
  move_piece_to_square(mv);
  update_king_position(mv);
}

void Board::move_piece_to_square(const Move &mv) {
  m_squares.do_move(mv);

  if (m_special_move.is_current_move_special_move())
    m_special_move.handle_special_move(mv, m_squares);

  update_half_moves(mv);
  update_full_moves();
}

void Board::update_king_position(const Move &mv) {
  Piecetype pct {Move_Utils::get_piece(mv)};
  if (!utils::check::is_king_piece(pct)) return;

  Color piece_color = utils::check::get_color_piece(pct);

    SquareIndices pos = Move_Utils::get_to(mv);
    update_king_position(piece_color, pos);
}

void Board::update_half_moves(const Move &m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);

  if (utils::check::is_pawn_piece(piece) || captured) {
    half_moves++;
    return;
  }

  half_moves = 0;
}

void Board::update_full_moves() { 
  full_moves++; 
}

int Board::get_half_moves() {
  return half_moves;
}

int Board::get_full_moves() {
  return half_moves;
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


BoardBitboard &Board::get_board_bitboard() { return m_board_bitboard; }

SquareIndices Board::get_king_position(Color c) {
  return c == BLACK ? m_black_king_position : m_white_king_position;
}

void Board::update_king_position(Color c, const SquareIndices &pos) {
  if (c == BLACK) {
    m_black_king_position = pos;
  } else if (c == WHITE) {
    m_white_king_position = pos;
  }
}

const int &Board::get_castle_permission() {
  return m_special_move.get_castle_permission();
}

const SquareIndices &Board::get_en_passant_square() {
  return m_special_move.get_en_passant_square();
}

// BoardFenInfo
Piecetype Board::get_piece_at_square(const size_t &pos) {
  return m_squares[pos].get_piece();
}

void Board::clear() {
  m_squares.clear();
  m_board_bitboard.clear();
}

void Board::set_piece_at_square(const SquareIndices &s, const Piecetype &p) {
  m_squares[static_cast<unsigned int>(s)].set_piece(p);
  m_board_bitboard.set_bit_at_player_pieces(utils::check::get_color_piece(p),
                                            s);
  if (utils::check::is_king_piece(p)) {
    update_king_position(utils::check::get_color_piece(p), s);
  }
}

void Board::set_castle_permission(CastlePermission perm) {
  m_special_move.set_castle_permission(perm);
}

void Board::set_en_passant_square(SquareIndices sq) {
  m_special_move.set_en_passant_square(sq);
}
