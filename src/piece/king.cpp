#include "headers/king.h"

template<Color color>
King<color>::King() :
  Piece(color == BLACK ? bK : wK) {
    _init_moves();
}

template<Color color>
King<color>::~King() {}

template<Color color>
bool King<color>::is_legal_non_attack_move(const Move& m, const BoardBitboard& board) {
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();
  const U64 free_squares = ~board.get_all_board_pieces();

  return m_attacks[from] & to & free_squares;
}

template<Color color>
bool King<color>::is_legal_attack_move(const Move& m, const BoardBitboard& board) {
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  const U64 opponent = 
    (color == BLACK) ? 
    board.get_all_white_pieces() : board.get_all_black_pieces();

  return m_attacks[from] & to & opponent;
}


