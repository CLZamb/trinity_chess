#include "headers/knight.h"

template<Color color>
Knight<color>::Knight() :
  Piece(color == BLACK ? bN : wN) {
    _init_moves();
}

template<Color color>
Knight<color>::~Knight() {}

template<Color color>
bool Knight<color>::is_legal_move(const Move& m){
  SquareIndices from = m.get_from();
  U64 to = ONE << m.get_to();

  return m_attacks[from] & to;
}



