#ifndef SQUARE_H
#define SQUARE_H

#pragma once
#include "graphics/headers/box.h"
#include "piece/headers/piece.h"
#include "graphics/headers/square_drawing.h"

class Square {
 public:
    Square();
    virtual ~Square ();

    void set_piece(Piecetype piece);
    void clear_square();
    Piecetype& get_piece();

 private:
    Piecetype m_piece = EMPTY;
};

#endif /* SQUARE_H */
