#include "board_check_behaviour.h"
#include "board/check_move/pieces/king.hpp"
#include "utils/bit_utilities.h"
#include "utils/defs.h"

CheckBehaviour::CheckBehaviour(Position& position, Color& side) : 
  m_side(side),
  m_position(position),
  m_bishop_attacks(m_magic_bitboard),
  m_queen_attacks(m_magic_bitboard),
  m_rook_attacks(m_magic_bitboard)
{}

bool CheckBehaviour::is_legal_move(Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  Piece captured = MoveUtils::get_captured_piece(m);
  Square to = MoveUtils::get_to(m);

  if (!piece) return false;
  if (!piece_belongs_to_player(piece)) return false;
  if (captured && are_same_color(piece, captured)) return false;

  if (utils::check::is_king_piece(piece) && can_opponent_attack_square(to)) return false;

  return m_pieces[piece]->is_legal_move(m, m_position);
}

bool CheckBehaviour::is_string_format_valid(const std::string& s)   {
  return string_utils::check::is_valid_move_format(s);
}

bool CheckBehaviour::is_player_in_check(const Move&)  {
  if (is_king_piece_attacked()) {
    return true;
  }

  // TODO(deux): 
  // if (!can_be_block_by_another_piece(m)) {
  //   return true;
  // }

  return false;
}

bool CheckBehaviour::is_checkmate()  {
  return check_checkmate();
}

bool CheckBehaviour::check_checkmate() {
  Bitboard all_king_possible_positions{get_all_king_possible_positions()};
  int count_possible_king_moves{0}, count_king_moves_blocked{0};
  Square position;

  while (all_king_possible_positions) {
    count_possible_king_moves++;
    position = static_cast<Square>(bitUtility::pop_1st_bit(&all_king_possible_positions));
    if (can_opponent_attack_square(position)) count_king_moves_blocked++;
  }

  return count_possible_king_moves == count_king_moves_blocked;
}

Bitboard CheckBehaviour::get_all_king_possible_positions() {
  Square sq = m_position.get_king_position(m_side);
  return King<WHITE>::king_mask(sq);
}

bool CheckBehaviour::piece_belongs_to_player(const Piece &pc) {
  return utils::check::get_color_piece(pc) == m_side;
}

bool CheckBehaviour::are_same_color(const Piece &piece,
                    const Piece &captured) {
  return utils::check::get_color_piece(piece) ==
  utils::check::get_color_piece(captured);
}

bool CheckBehaviour::can_check(const Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  return !utils::check::is_king_piece(piece) && (is_king_piece_attacked());
}

bool CheckBehaviour::can_be_block_by_another_piece(const Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  if (utils::check::is_king_piece(piece)) return false;

  bool is_king_in_check{false};

  m_position.make_move(m);
  is_king_in_check = can_check(m);
  m_position.undo_move(m);

  return !is_king_in_check;
}

bool CheckBehaviour::is_king_piece_attacked() {
  Square sq = m_position.get_king_position(m_side);
  return can_opponent_attack_square(sq);
}

Color CheckBehaviour::get_opponent_player_color() {
  return m_side == WHITE ? BLACK : WHITE;
}

bool CheckBehaviour::can_opponent_attack_square(const Square &sq) {
  Color opposite_color = get_opponent_player_color();
  Bitboard opposite_player_bitboard =  m_position.get_occupied_side_as_bitboard(opposite_color);
  Bitboard temp_iterable_bb = opposite_player_bitboard;
  Bitboard attack_bitboard{ZERO};
  Piece pt;
  Square position{0};

  while (temp_iterable_bb) {
    position = static_cast<Square>(bitUtility::pop_1st_bit(&temp_iterable_bb));

    pt = m_position.get_piece_at_square(position);

    attack_bitboard |= m_pieces[pt]->get_attacks(opposite_player_bitboard, position);
  }

  Bitboard to_bb = ONE << sq;
  return attack_bitboard & to_bb;
}
