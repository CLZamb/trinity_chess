#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <string>
#include "common/headers/common.h"
#include "graphics/headers/box.h"
#include "graphics/headers/pieces_drawings.hpp"
#include "board/headers/utils.h"
#include "game/headers/move.h"
#include "board/headers/BoardBitboard.h"

using namespace bitUtility;

class Piece {
 public:
    virtual ~Piece();
    Piecetype get_type_and_color();
    virtual bool is_legal_non_attack_move(Move &, BoardBitboard& board) = 0;
    virtual bool is_legal_attack_move(Move&, BoardBitboard& board) = 0;

 protected:
    explicit Piece(const Piecetype&);
    U64 m_attacks[utils::constant::ksquares] = { BLANK };

 private:
    Piecetype m_type;
};



#endif /* PIECE_H */
