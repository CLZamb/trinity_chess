#include "headers/knight.h"

template<Color color>
Knight<color>::Knight() :
  Piece(color == BLACK ? bN : wN) {
    _init_moves();
}

template<Color color>
Knight<color>::~Knight() {}

template<Color color>
bool Knight<color>::is_legal_non_attack_move(Move& m, BoardBitboard& board) {
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();
  const U64 free_squares = ~board.get_all_board_pieces();

  return m_attacks[from] & to & free_squares;
}

template<Color color>
bool Knight<color>::is_legal_attack_move(Move& m, BoardBitboard& board) {
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  const U64 opponent = board.get_all_side_pieces(color == BLACK);

  return m_attacks[from] & to & opponent;
}
