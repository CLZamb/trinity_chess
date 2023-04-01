#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <string>
#include "utilities.h"
#include "board_bitboard.h"

using namespace bitUtility;

class Piece {
public:
  virtual ~Piece();
  Piecetype get_piecetype();
  virtual bool is_legal_move(Move &, BoardBitboard &) = 0;
  // virtual void get_all_possible_positions(Move&, BoardBitboard &, U64& result) = 0;

protected:
  explicit Piece(const Piecetype &);
  U64 m_attacks[utils::constant::ksquares] = {BLANK};

private:
  Piecetype _m_type;
};

#endif /* PIECE_H */
