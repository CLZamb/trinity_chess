#include "headers/bishop.h"

template<Color color>
Bishop<color>::Bishop(const MagicBitboard& m_bb) :
  Piece(color == BLACK ? bB : wB),
  m_bb{&m_bb} {}

template<Color color>
Bishop<color>::~Bishop() {}

template<Color color>
bool Bishop<color>::is_legal_non_attack_move(const Move& m, const BoardBitboard& board) {
  if (m_bb == nullptr) return false;

  U64 all_moves = BLANK;
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();
  const U64 own_color_pieces = 
    (color == BLACK) ? 
    board.get_all_black_pieces() : board.get_all_white_pieces();

  all_moves = m_bb->bishop_attacks(board.get_all_board_pieces(), from);
  return all_moves & to & ~own_color_pieces;
}

template<Color color>
bool Bishop<color>::is_legal_attack_move(const Move& m, const BoardBitboard& board) {
  if (m_bb == nullptr) return false;

  U64 all_moves = BLANK;
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();
  const U64 opponent = 
    (color == BLACK) ? 
    board.get_all_white_pieces() : board.get_all_black_pieces();

  all_moves = m_bb->bishop_attacks(board.get_all_board_pieces(), from);
  return all_moves & to & opponent;
}
