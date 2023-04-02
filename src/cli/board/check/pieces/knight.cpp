#include "knight.h"

template<Color color>
Knight<color>::Knight() :
  Piece(color == BLACK ? bN : wN) {
    _init_moves();
}

template<Color color>
Knight<color>::~Knight() {}

template<Color color>
bool Knight<color>::is_legal_move(Move& m, BoardBitboard& board) {
  SquareIndices from = Move_Utils::get_from(m);
  U64 to = ONE << Move_Utils::get_to(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);
  U64 free_squares = ~board[BOTH];

  if (captured) {
    free_squares |= board[utils::check::get_color_piece(captured)];
  }

  return m_attacks[from] & to & free_squares;
}

// template<Color color>
// U64 Knight<color>::get_all_possible_positions(Move& m, BoardBitboard& board) {
//   SquareIndices from = Move_Utils::get_from(m);
//   U64 free_squares = ~board[BOTH];
//
//   return m_attacks[from] & free_squares;
// }
