#ifndef MOVE_H
#define MOVE_H
#include "../defs.h"
#include <iostream>
/*
  change it to 0x3f because it only uses 63 moves
  0000 0000 0000 0000 0000 0111 1111 -> From 0x7F
  0000 0000 0000 0011 1111 1000 0000 -> To >> 7, 0x7F
  0000 0000 0011 1100 0000 0000 0000 -> Captured >> 14, 0xF
  0000 0000 0100 0000 0000 0000 0000 -> EnPessant 0x40000
  0000 0000 1000 0000 0000 0000 0000 -> Pawn Start 0x80000
  0000 1111 0000 0000 0000 0000 0000 -> Promoted Piece >> 20, 0xF
  0001 0000 0000 0000 0000 0000 0000 -> Castle 0x1000000
*/

class Move {
 public:
  Move() {}
  explicit Move(int m) : m_move(m) { }
  Move(unsigned int from, unsigned int to, unsigned int flags) {
    m_move = (from & 0x7f) | ((to & 0x7f) << 7) | ((flags & 0xf) << 14);
  }

  // void operator=(Move a) {
  //   m_move = a.m_move;
  //   m_input = a.m_input;
  //   m_validMove = a.m_validMove;
  // }

  unsigned int get_to() const { return (m_move >> 7) & 0x3f; }
  unsigned int get_from() const { return m_move & 0x3f; }
  unsigned int get_flags() const { return (m_move >> 14) & 0x0f; }
  unsigned int get_captured_piece() const { return (m_move >> 14) & 0x0f; }

  void set_to(unsigned int to) {
    m_move &= ~0xf80;
    m_move |= (to & 0x3f) << 7;
  }
  void set_from(unsigned int from) {
    m_move &= ~0x7f;
    m_move |= (from & 0x3f);
  }
  void set_move(unsigned int from, unsigned int to, unsigned int flags) {
    m_move = (from & 0x7f) | ((to & 0x7f) << 7) | ((flags & 0xf) << 14);
  }

  void set_capture_piece(unsigned int piece) {
    m_move |= piece << 14;
  }

  void set_valid_move(bool v) { m_valid_move = v; }
  bool is_valid_move() { return m_valid_move; }

  bool is_capture() const { return (m_move & CAPTURE_FLAG) != 0; }

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

 private:
  std::string m_input = "quit";
  bool m_valid_move = false;
  // int m_piece;
  // int m_capturedPiece;
  // char m_piece_promoted_to;
  // bool m_castle;
  // bool m_en_passant;
  unsigned int m_move; // or short or template type
  int CAPTURE_FLAG;
};

#endif /* MOVE_H */
