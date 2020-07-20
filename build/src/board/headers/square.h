#ifndef SQUARE_H
#define SQUARE_H

#pragma once
#include "../headers/box.h"
#include "../headers/piece.h"

class Square {
 public:
    Square(box*, bool);
    virtual ~Square ();

    void set_piece(Piece* piece);
    void clear_square();
    char* at(int i);
    bool is_black_square();
    Piece* get_piece();
    box* get_current_drawing();

 private:
    box* p_empty_square_drawing = nullptr;
    box* p_cur_drawing = nullptr;
    Piece* p_piece = nullptr;
    bool m_is_black_square = false;
};

#endif /* SQUARE_H */
