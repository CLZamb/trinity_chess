#ifndef SQUARE_H
#define SQUARE_H

#pragma once
#include "../../graphics/headers/box.h"
#include "../../piece/headers/piece.h"
#include "../../graphics/headers/square_drawing.h"

class Square {
 public:
    Square();
    Square(bool is_black_square);
    virtual ~Square ();

    void set_color(bool is_black_square);
    void set_piece(Piece* piece);
    void clear_square();
    char* at(int i);
    bool is_black_square();
    Piece* get_piece();
    Box* get_current_drawing();

 private:
    SquareDrawing square_drawing;
    Piece* p_piece = nullptr;
    bool m_is_black_square = false;
};

#endif /* SQUARE_H */
