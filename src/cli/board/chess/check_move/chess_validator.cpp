#include "chess_validator.h"

ChessValidator::ChessValidator(Position &p)
    : m_position(p)
    , m_pieces_legal_moves(m_position, m_side) {}

void ChessValidator::update_turn(const Color &side) { m_side = side; }

bool ChessValidator::is_player_in_check(const Move &) {
  if (m_pieces_legal_moves.is_king_piece_attacked()) {
    return true;
  }

  // TODO(deux):
  // if (!can_be_block_by_another_piece(m)) {
  //   return true;
  // }

  return false;
}

bool ChessValidator::is_string_move_format_valid(const std::string &s) {
  return StringUtils::check::is_valid_move_format(s);
}

bool ChessValidator::is_legal_move(Move &m) {
  Piece piece = MoveUtils::get_piece(m);
  Piece captured = MoveUtils::get_captured_piece(m);
  Square to = MoveUtils::get_to(m);

  if (!piece) return false;
  if (!piece_belongs_to_player(piece)) return false;
  if (captured && are_same_color(piece, captured)) return false;

  if (utils::check::is_king_piece(piece) &&
      m_pieces_legal_moves.can_opponent_attack_square(to)) {
    return false;
  }

  return m_pieces_legal_moves.is_legal_move(m);
}

bool ChessValidator::piece_belongs_to_player(const Piece &pc) {
  return utils::check::get_color_piece(pc) == m_side;
}

bool ChessValidator::is_checkmate() {
  Bitboard all_king_possible_positions{
      m_pieces_legal_moves.get_all_king_possible_positions()};
  int count_possible_king_moves{0}, count_king_moves_blocked{0};
  Square position;

  while (all_king_possible_positions) {
    count_possible_king_moves++;
    position = static_cast<Square>(
        bitUtility::pop_1st_bit(&all_king_possible_positions));
    if (m_pieces_legal_moves.can_opponent_attack_square(position))
      count_king_moves_blocked++;
  }

  return count_possible_king_moves == count_king_moves_blocked;
}

bool ChessValidator::are_same_color(const Piece &piece, const Piece &captured) {
  return utils::check::get_color_piece(piece) ==
         utils::check::get_color_piece(captured);
}
