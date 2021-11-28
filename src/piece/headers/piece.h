#ifndef PIECE_H
#define PIECE_H

#include <array>
#include <string>
#include "../../include/common/headers/common.h"
// #include "utils.h"
#include "../../graphics/headers/box.h"
#include "../../graphics/headers/pieces_drawings.hpp"
#include "../../board/headers/utils.h"
#include "../../headers/move.h"
#include "../../board/headers/bit_utilities.h"
#include "../../board/headers/BoardBitboard.h"

using namespace bitUtility;

class Piece {
 public:
    virtual ~Piece();
    bool is_black();
    Box* get_drawing(bool is_in_a_black);
    Piecetype get_type_and_color();
    bool is_black_piece(int pct);
    virtual bool is_legal_non_attack_move(const Move&, const BoardBitboard& board) = 0;
    virtual bool is_legal_attack_move(const Move&, const BoardBitboard&  board) = 0;

 protected:
    explicit Piece(const Piecetype&);
    U64 m_attacks[utils::constant::ksquares] = { BLANK };
    PieceDrawing* create_drawing(const Piecetype& m_type);

 private:
    StandardDrawingBuilder drawing_builder;
    Piecetype m_type;
    bool black = false;
    PieceDrawing* p_piece_drawing;
};



#endif /* PIECE_H */
