#ifndef PIECE_H
#define PIECE_H

#include "board/position/position.h"

class PieceBase {
 public:
  virtual ~PieceBase();
  Piece get_piecetype();
  virtual bool is_legal_move(Move &, Position &) = 0;
  virtual Bitboard get_attacks(Bitboard bb, Square sq) = 0;

 protected:
  explicit PieceBase(const Piece &);
  Bitboard m_attacks[utils::constant::ksquares] = {BLANK};

 private:
  Piece _m_type;
};

#endif /* PIECE_H */
