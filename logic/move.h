#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <cassert>
#include "../defs.h"
/*
  0000 0000 0000 0000 0000 0011 1111 -> From 0x3F
  0000 0000 0000 0000 1111 1100 0000 -> To >> 6, 0x3F
  0000 0000 0000 1111 0000 0000 0000 -> Captured >> 12, 0xF
  0000 0000 0001 0000 0000 0000 0000 -> EnPessant >> 16, 0x1
  0000 0001 1110 0000 0000 0000 0000 -> Piece >> 17, 0xF
  0001 1110 0000 0000 0000 0000 0000 -> Promoted Piece >> 21, 0xF
  0010 0000 0000 0000 0000 0000 0000 -> Castle >> 25, 0x1
*/

class Move {
 public:
  Move() {}
  explicit Move(int m) : m_move(m) { }
  Move(int m, int sc) : m_move(m), m_score(sc) {}
  Move(unsigned int from, unsigned int to, unsigned int type) {
    m_move = (from & 0x3f) | ((to & 0x3f) << 6) | ((type & 0xf) << 17);
  }

  unsigned int get_move() { return m_move; }
  unsigned int get_from() const { return m_move & 0x3f; }
  unsigned int get_to() const { return (m_move >> 6) & 0x3f; }
  unsigned int get_captured_piece() const { return (m_move >> 12) & 0xf; }
  unsigned int get_piece() const { return (m_move >> 17) & 0xf; }
  unsigned int get_score() const { return m_score; }
  // bool is_en_pessand() const { (m_move >> 16) & 0x1; }
  void set_to(unsigned int to) {
    m_move &= ~0xfc0;
    m_move |= (to & 0x3f) << 6;
    assert(to == ((m_move >> 6) & 0x3f));
  }

  void set_from(unsigned int from) {
    m_move &= ~0x3f;
    m_move |= (from & 0x3f);
    assert(from == (m_move & 0x3f));
  }

  void set_move(unsigned int from, unsigned int to, unsigned int type) {
    m_move = (from & 0x3f) | ((to & 0x3f) << 6) | ((type & 0xf) << 17);
  }

  void set_move(unsigned int from, unsigned int to) {
    m_move = (from & 0x3f) | ((to & 0x3f) << 6);
  }

  void set_move(unsigned int m) { m_move = m; }

  void set_capture_piece(unsigned int piece) {
    assert(piece);
    if (!piece)
      return;

    m_move &= ~0xf000;
    m_move |= ((piece & 0xf) << 12);
    assert(piece == ((m_move >> 12) & 0xf));
  }

  void set_piece(unsigned int piece) {
    m_move &= ~0x1e0000;
    m_move |= ((piece & 0xf) << 17);

    assert(piece == ((m_move >> 17) & 0xf));
  }

  void set_score(int score) { m_score = score; }

  bool operator==(Move a) const {
    return (m_move & 0xffff) == (a.m_move & 0xffff);
  }

  bool operator!=(Move a) const {
    return (m_move & 0xffff) != (a.m_move & 0xffff);
  }

  static unsigned int GetFrom(int mv) {
    return mv & 0x3f;
  }

  static unsigned int GetTo(int mv) {
    return (mv >> 6) & 0x3f;
  }

  static unsigned int GetPiece(int mv) {
    return (mv >> 17) & 0xf;
  }

  static unsigned int GetCapture(int mv) {
    return (mv >> 12) & 0xf;
  }

 private:
  unsigned int m_move = 0;  // or short or template type
  int m_score = 0;
};

#endif /* MOVE_H */
