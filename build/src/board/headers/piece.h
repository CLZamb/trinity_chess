#ifndef PIECE_H
#define PIECE_H

#include <string>
// #include "bitUtilities.hpp"
#include "../../../include/common/headers/common.h"
// #include "utils.h"
#include "box.h"
#include "pieces_drawings.hpp"
#include "utils.h"

class Piece {
  public:
    explicit Piece(Piecetype pct);
    virtual ~Piece();
    bool is_black();
    void create_drawing(string piece_type);
    box* get_drawing(bool is_black);
    Piecetype get_type_and_color();

  private:
    bool black = false;
    Piecetype m_type = EMPTY;
    Drawing* white_square_drawing = nullptr;
    Drawing* black_square_drawing = nullptr;
};

#endif /* PIECE_H */
