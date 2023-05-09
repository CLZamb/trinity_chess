#include "board_representation.h"

#include "board/position/position_utils.h"
#include "utils/bit_utilities.h"
#include "utils/move.hpp"

BoardRepresentation::BoardRepresentation() {}

bool BoardRepresentation::is_occupied_at_square(const Square pos) {
  return m_all_occupancies & (ONE << pos);
}

void BoardRepresentation::move_piece(const Piece p,
                                     const Square from,
                                     const Square to) {
  clear_piece_at_square(p, from);
  set_piece_at_square(p, to);
}

Bitboard BoardRepresentation::get_occupied_side_as_bitboard(Color c) {
  return m_side_occupancies[c];
}

Bitboard BoardRepresentation::get_occupied_squares_as_bitboard() {
  return m_all_occupancies;
}

void BoardRepresentation::set_piece_at_square(Piece p, Square square) {
  if (utils::check::is_king_piece(p)) {
    king_position[utils::check::get_color_piece(p)] = square;
  }

  Color color = utils::check::get_color_piece(p);
  bitUtility::set_bit(&m_side_occupancies[color], square);
  bitUtility::set_bit(&m_all_occupancies, square);

  m_pieces_pos[square] = p;
}

void BoardRepresentation::clear_piece_at_square(Piece p, Square square) {
  m_pieces_pos[square] = NO_PIECE;

  Color color = utils::check::get_color_piece(p);
  bitUtility::clear_bit(&m_side_occupancies[color], square);
  bitUtility::clear_bit(&m_all_occupancies, square);
}

void BoardRepresentation::clear() {
  for (Square sq = A1; sq <= A8; ++sq) {
    m_pieces_pos[sq] = NO_PIECE;
  }

  for (Color c : {WHITE, BLACK}) {
    m_side_occupancies[c] = BLANK;
  }

  m_all_occupancies = BLANK;
}

void BoardRepresentation::clear_square(Square sq) {
  clear_piece_at_square(m_pieces_pos[sq], sq);
}

const Piece &BoardRepresentation::get_piece_at_square(Square sq) const {
  return m_pieces_pos[sq];
}

Square BoardRepresentation::get_king_position(Color c) {
  return king_position[c];
}

void BoardRepresentation::update_king_position(const Move &mv) {
  Piece pct{MoveUtils::get_piece(mv)};
  if (!utils::check::is_king_piece(pct)) {
    return;
  }

  Color piece_color = utils::check::get_color_piece(pct);

  Square pos = MoveUtils::get_to(mv);
  update_king_position(piece_color, pos);
}

void BoardRepresentation::update_king_position(Color c, const Square &pos) {
  king_position[c] = pos;
}
