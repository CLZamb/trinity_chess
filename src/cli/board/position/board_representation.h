#ifndef BOARD_REPRESENTATION_H
#define BOARD_REPRESENTATION_H

#include "board/position/position_typedefs.h"
#include "game/game_typedefs.h"
#include "utils/defs.h"
#include "utils/move.hpp"

class BoardRepresentation {
 public:
  BoardRepresentation();
  void set_piece_at_square(Piece p, Square position);
  void clear_piece_at_square(Piece p, Square position);
  void clear_square(Square s);
  void clear();
  void move_piece(const Piece p, const Square from, const Square to);
  const Piece &get_piece_at_square(Square sq) const;
  Square get_king_position(Color c);
  void update_king_position(Color c, const Square &pos);
  void update_king_position(const Move &mv);
  bool is_occupied_at_square(const Square position);
  Bitboard get_occupied_side_as_bitboard(Color c);
  Bitboard get_occupied_squares_as_bitboard();

 private:
  BoardSquares m_pieces_pos{EMPTY};
  std::array<Square, Color::SIZE> king_position{SquareNull};
  std::array<Bitboard, Color::SIZE> m_side_occupancies{ZERO};
  Bitboard m_all_occupancies{ZERO};
};

#endif /* BOARD_REPRESENTATION_H */
