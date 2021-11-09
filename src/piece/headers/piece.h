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

using namespace bitUtility;

class Piece {
 public:
    virtual ~Piece();
    bool is_black();
    box* get_box_drawing(bool is_black);
    Piecetype get_type_and_color();
    bool is_black_piece(int pct);
    virtual bool is_legal_move(const Move&) = 0;

 protected:
    explicit Piece(const Piecetype&);
    PieceDrawing* create_drawing(const Piecetype& m_type);
    U64 m_attacks[utils::constant::ksquares] = { BLANK };

 private:
    StandardDrawingBuilder drawing_builder;
    Piecetype m_type;
    bool black = false;
    PieceDrawing* p_piece_drawing;
};



#endif /* PIECE_H */
