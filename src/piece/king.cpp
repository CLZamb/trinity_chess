#include "headers/king.h"

template<Color color>
King<color>::King() :
  Piece(color == BLACK ? bK : wK) {
    _init_moves();
}

template<Color color>
King<color>::~King() {}

template<Color color>
bool King<color>::is_legal_move(const Move& m){
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  return m_attacks[from] & to;
}



