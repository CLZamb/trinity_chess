#ifndef MOVE_H
#define MOVE_H

#include "board/headers/utils.h"
#include <cassert>

/*
   0000 0000 0000 0000 0000 0011 1111 -> From 0x3F
   0000 0000 0000 0000 1111 1100 0000 -> To >> 6, 0x3F
   0000 0000 0000 1111 0000 0000 0000 -> Captured >> 12, 0xF
   0000 0000 0001 0000 0000 0000 0000 -> EnPessant >> 16, 0x1
   0000 0001 1110 0000 0000 0000 0000 -> Piece >> 17, 0xF
   0001 1110 0000 0000 0000 0000 0000 -> Promoted Piece >> 21, 0xF
   0010 0000 0000 0000 0000 0000 0000 -> Castle >> 25, 0x1
 */

typedef unsigned int Move;

namespace Move_Utils {
inline SquareIndices get_from(const Move &m) {
  return static_cast<SquareIndices>(m & 0x3f);
}

inline SquareIndices get_to(const Move &m) {
  return static_cast<SquareIndices>((m >> 6) & 0x3f);
}

inline Piecetype get_captured_piece(const Move &m) {
  return static_cast<Piecetype>((m >> 12) & 0xf);
}

inline Piecetype get_piece(const Move &m) {
  return static_cast<Piecetype>((m >> 17) & 0xf);
}

inline bool is_en_pessand(const Move &m) { 
  return (m >> 16) & 0x1; 
}

inline void set_en_passant(Move &m, bool is_en_passant) {
  m &= ~0x1;
  m |= ((is_en_passant ? ONE : BLANK) & 0x1) << 16;
}

inline void set_to(Move &m, int to) {
  m &= ~0xfc0;
  m |= (to & 0x3f) << 6;
  assert(to == ((m >> 6) & 0x3f));
}

inline void set_from(Move &m, unsigned int from) {
  m &= ~0x3f;
  m |= (from & 0x3f);
  assert(from == (m & 0x3f));
}

inline Move make_move(int from, unsigned int to, unsigned int piece_type) {
  return (from & 0x3f) | ((to & 0x3f) << 6) | ((piece_type & 0xf) << 17);
}

inline void set_move(Move &m, unsigned int from, unsigned int to) {
  m = (from & 0x3f) | ((to & 0x3f) << 6);
}

inline void set_capture_piece(Move &m, unsigned int piece) {
  m &= ~0xf000;
  m |= ((piece & 0xf) << 12);
}

inline void set_piece(Move &m, unsigned int piece) {
  m &= ~0x1e0000;
  m |= ((piece & 0xf) << 17);

  assert(piece == ((m >> 17) & 0xf));
}
} // namespace Move_Utils

#endif /* MOVE_H */
