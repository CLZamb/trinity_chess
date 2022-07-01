#include "headers/king.h"

template <Color color> King<color>::King() : Piece(color == BLACK ? bK : wK) {
  _init_moves();
}

template <Color color> King<color>::~King() {}

template <Color color>
bool King<color>::is_legal_move(Move &m, BoardBitboard &board) {
  SquareIndices from = Move_Utils::get_from(m);
  U64 to = ONE << Move_Utils::get_to(m);
  Piecetype captured = Move_Utils::get_captured_piece(m);
  U64 free_squares = ~board[BOTH];

  if (captured) {
    free_squares |= board[utils::check::get_color_piece(captured)];
  }

  return m_attacks[from] & to & free_squares;
}
