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
  explicit Move(int m) : m_Move(m) { }
  Move(unsigned int from, unsigned int to, unsigned int flags) {
    m_Move = (from & 0x7f) | ((to & 0x7f) << 7) | ((flags & 0xf) << 14);
  }

  // void operator=(Move a) {
  //   m_Move = a.m_Move;
  //   m_input = a.m_input;
  //   m_validMove = a.m_validMove;
  // }

  unsigned int getTo() const { return (m_Move >> 7) & 0x3f; }
  unsigned int getFrom() const { return m_Move & 0x3f; }
  unsigned int getFlags() const { return (m_Move >> 14) & 0x0f; }
  unsigned int getCapturedPiece() const { return (m_Move >> 14) & 0x0f; }
  bool getValidMove() { return m_validMove; }

  void setTo(unsigned int to) {
    m_Move &= ~0xf80;
    m_Move |= (to & 0x3f) << 7;
  }
  void setFrom(unsigned int from) {
    m_Move &= ~0x7f;
    m_Move |= (from & 0x3f);
  }
  void setMove(unsigned int from, unsigned int to, unsigned int flags) {
    m_Move = (from & 0x7f) | ((to & 0x7f) << 7) | ((flags & 0xf) << 14);
  }

  void setCapturePiece(unsigned int piece) {
    m_Move |= piece << 14;
  }

  void setValidMove(bool v) { m_validMove = v; }

  bool isCapture() const { return (m_Move & CAPTURE_FLAG) != 0; }

  unsigned int getButterflyIndex() const { return m_Move & 0x0fff; }
  bool operator==(Move a) const {
    return (m_Move & 0xffff) == (a.m_Move & 0xffff);
  }
  bool operator!=(Move a) const {
    return (m_Move & 0xffff) != (a.m_Move & 0xffff);
  }

  unsigned short asShort() const { return (unsigned short)m_Move; }

  std::string m_input = "quit";
  bool m_validMove = false;
 private:
  int m_piece;
  int m_capturedPiece;
  char m_piece_promoted_to;
  bool m_castle;
  bool m_en_passant;
  unsigned int m_Move; // or short or template type
  int CAPTURE_FLAG;
};

#endif /* MOVE_H */
