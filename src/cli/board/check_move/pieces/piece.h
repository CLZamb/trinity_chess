#ifndef PIECE_H
#define PIECE_H

#include "board/board_representation/board_bitboard.h"
#include "utils/utilities.h"

using namespace bitUtility;

class Piece {
public:
  virtual ~Piece();
  Piecetype get_piecetype();
  virtual bool is_legal_move(Move &, BoardBitboard &) = 0;

protected:
  explicit Piece(const Piecetype &);
  U64 m_attacks[utils::constant::ksquares] = {BLANK};

private:
  Piecetype _m_type;
};

#endif /* PIECE_H */
