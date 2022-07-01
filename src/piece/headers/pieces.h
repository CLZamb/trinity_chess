#ifndef PIECES_H
#define PIECES_H 

#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"

class Pieces {
 public:
    Pieces();
    virtual ~Pieces();
    Piece* operator[](Piecetype type);
    void make_pawn(const Color C);
    void make_rook(const Color C);
    void make_bishop(const Color C);
    void make_queen(const Color C);
    void make_king(const Color C);
    void make_knight(const Color C);


 private:
    void create_all_pieces();
    MagicBitboard m_magic_bitboard;
    RookMagicBitboard m_rook_magic_bitboard;
    QueenMagicBitboard m_queen_magic_bitboard;
    BishopMagicBitboard m_bishop_magic_bitboard;
    std::array<Piece*, 13> m_pieces { nullptr };
    static const int m_max_size = 13;
};

#endif /* ifndef PIECES_H */
