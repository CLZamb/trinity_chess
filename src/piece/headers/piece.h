#ifndef PIECE_H
#define PIECE_H

#include "board/headers/BoardBitboard.h"
#include "board/headers/utils.h"
#include "common/headers/common.h"
#include "game/headers/move.hpp"
#include "graphics/headers/box.h"
#include "graphics/headers/pieces_drawings.hpp"
#include <array>
#include <string>

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
