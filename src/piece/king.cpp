#include "headers/king.h"

template<Color color>
King<color>::King() :
  Piece(color == BLACK ? bK : wK) {
    _init_moves();
}

template<Color color>
King<color>::~King() {}

template<Color color>
bool King<color>::is_legal_non_attack_move(Move &m, BoardBitboard& board) {
  SquareIndices from = Move_Utils::get_from(m);
  U64 to = ONE << Move_Utils::get_to(m);
  const U64 free_squares = ~board[BOTH];

  return m_attacks[from] & to & free_squares;
}

template<Color color>
bool King<color>::is_legal_attack_move(Move &m, BoardBitboard& board) {
  SquareIndices from = Move_Utils::get_from(m);
  U64 to = ONE << Move_Utils::get_to(m);

  const U64 opponent = board[BOTH];

  return m_attacks[from] & to & opponent;
}


