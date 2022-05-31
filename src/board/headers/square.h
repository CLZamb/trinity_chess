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

    void set_piece(Piece* piece);
    void clear_square();
    Piece* get_piece();

 private:
    Piece* p_piece = nullptr;
};

#endif /* SQUARE_H */
