#ifndef SQUARE_H
#define SQUARE_H

#pragma once
#include "../../graphics/headers/box.h"
#include "../../piece/headers/piece.h"

class Square {
 public:
    Square(Box*, bool);
    virtual ~Square ();

    void set_piece(Piece* piece);
    void clear_square();
    char* at(int i);
    bool is_black_square();
    Piece* get_piece();
    Box* get_current_drawing();

 private:
    Box* p_empty_square_drawing = nullptr;
    Box* p_cur_drawing = nullptr;
    Piece* p_piece = nullptr;
    bool m_is_black_square = false;
};

#endif /* SQUARE_H */
