#ifndef MOVE_H
#define MOVE_H
#include "../defs.h"
#include <iostream>
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
  Move(unsigned int from, unsigned int to, unsigned int captured) {
    m_move = (from & 0x3f) | ((to & 0x3f) << 6) | ((captured & 0xf) << 12);
  }

  unsigned int get_from() const { return m_move & 0x3f; }
  unsigned int get_to() const { return (m_move >> 6) & 0x3f; }
  unsigned int get_captured_piece() const { return (m_move >> 12) & 0xf; }
  unsigned int get_piece() const { return (m_move >> 17) & 0xf; }

  bool is_en_pessand() const { (m_move >> 16) & 0x1; }
  void set_to(unsigned int to) {
    m_move &= ~0x3f;
    m_move |= (to & 0x3f) << 6;
  }

  void set_from(unsigned int from) {
    m_move &= ~0x3f;
    m_move |= (from & 0x3f);
  }

  void set_move(unsigned int from, unsigned int to, unsigned int captured) {
    m_move = (from & 0x3f) | ((to & 0x3f) << 6) | ((captured & 0xf) << 12);
  }

  void set_move(unsigned int from, unsigned int to) {
    m_move = (from & 0x3f) | ((to & 0x3f) << 6);
  }

  void set_capture_piece(unsigned int piece) {
    if (!piece)
      return;

    m_move |= ((piece & 0xf) << 12);
  }

  void set_piece(unsigned int piece) {
    m_move |= ((piece & 0xf) << 17);
  }

  void set_valid_move(bool v) { m_valid_move = v; }

  bool is_valid_move() { return m_valid_move; }

  unsigned int get_butterfly_index() const { return m_move & 0x0fff; }
  bool operator==(Move a) const {
    return (m_move & 0xffff) == (a.m_move & 0xffff);
  }
  bool operator!=(Move a) const {
    return (m_move & 0xffff) != (a.m_move & 0xffff);
  }

  unsigned short as_short() const { return (unsigned short)m_move; }
  std::string get_str_input() { return m_input; }
  void set_str_input(std::string input) { m_input = input; }
  unsigned int get_uint_move() const { return m_move; }

 private:
  std::string m_input = "quit";
  bool m_valid_move = false;
  unsigned int m_move; // or short or template type
};

#endif /* MOVE_H */
