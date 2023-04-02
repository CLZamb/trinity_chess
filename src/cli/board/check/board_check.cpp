#include "board_check.h"

BoardCheck::BoardCheck(Board& b):
  m_board(b),
  m_board_bitboard(b.get_board_bitboard()) {}

void BoardCheck::update_turn(const PlayerInfo &turn) { m_turn_info = turn; }

bool BoardCheck::is_legal_move(Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);
  SquareIndices to = Move_Utils::get_to(m);

  if (!piece) return false;

  if (!check_piece_belongs_to_player(piece)) return false;

  if (captured && is_captured_piece_same_color(piece, captured)) return false;

  if (is_king_piece(piece) && can_opponent_attack_square(to)) return false;

  return m_pieces[piece]->is_legal_move(m, m_board_bitboard);
}

bool BoardCheck::check_piece_belongs_to_player(const Piecetype &pc) {
  return utils::check::get_color_piece(pc) == m_turn_info.color;
}

bool BoardCheck::is_captured_piece_same_color(const Piecetype &piece,
                                            const Piecetype &captured) {
  return utils::check::get_color_piece(piece) ==
         utils::check::get_color_piece(captured);
}

bool BoardCheck::is_king_piece(const Piecetype& pct) {
  return (pct == wK) || (pct == bK);
}

bool BoardCheck::can_opponent_attack_square(const unsigned int &to) {
  SquareIndices from;
  Move m;
  Piecetype pt;
  Color opposite_color = get_opponent_player_color();

  for (const size_t& i: m_board_bitboard.get_all_locations_at_side(opposite_color)) {
    pt = m_board.get_piece_at_square(i);
    from = static_cast<SquareIndices>(i);
    m = Move_Utils::make_move(from, to, pt);
    if (pt && !is_king_piece(pt))
      if (m_pieces[pt]->is_legal_move(m, m_board_bitboard)) { return true; }
  }
  return false;
}

Color BoardCheck::get_opponent_player_color() {
  return m_turn_info.color == WHITE ? BLACK : WHITE;
}

bool BoardCheck::is_checkmate() {
  check_checkmate();
  return checkmate; 
}

void BoardCheck::check_checkmate() {
  U64 all_king_possible_positions{get_all_king_possible_positions()};
  int count_possible_king_moves{0}, count_king_moves_blocked{0};
  unsigned int position;

  while (all_king_possible_positions) {
    count_possible_king_moves++;
    position = static_cast<unsigned int>(pop_1st_bit(&all_king_possible_positions));
    if (can_opponent_attack_square(position))count_king_moves_blocked++;
  }

  checkmate = count_possible_king_moves == count_king_moves_blocked;
}

U64 BoardCheck::get_all_king_possible_positions() {
  Color c = m_turn_info.color;
  SquareIndices sq = m_board.get_king_position(c);
  return King<WHITE>::king_mask(sq);
}

bool BoardCheck::is_in_check(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  if (!is_king_piece(piece) && (is_king_piece_attacked())) {
      return true;
  }
  return false;
}

bool BoardCheck::is_king_piece_attacked() {
  SquareIndices sq = m_board.get_king_position(m_turn_info.color);
  return can_opponent_attack_square(sq);
}

bool BoardCheck::can_be_block_by_another_piece(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  if (is_king_piece(piece)) return false;

  bool is_king_in_check = false;

  m_board_bitboard.move(m);
  is_king_in_check = is_in_check(m);
  m_board_bitboard.undo_move(m);

  return !is_king_in_check;
}

