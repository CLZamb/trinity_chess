// File: pawn.h
#ifndef PAWN_H
#define PAWN_H

#pragma once
#include "piece.h"

class Pawn : public Piece {
 private:
    static box pawn_w_sq_p2;
    static box pawn_b_sq_p2;
    static box pawn_w_sq_p1;
    static box pawn_b_sq_p1;

 public:
    explicit Pawn(bool black, U64);
    virtual ~Pawn();
    std::string get_type();
};
#endif /* PAWN_H */
