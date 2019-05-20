#ifndef MAGIC_BITBOARD_H
#define MAGIC_BITBOARD_H
#include <iostream>
#include "../defs.h"

class MagicBitboard
{
  private:
    struct SMagic {
      U64* attacks;  // pointer to attack_table for each particular square
      U64 mask;  // to mask relevant squares of both lines (no outer squares)
      U64 magic;  // magic 64-bit factor
      int shift;  // shift right
    };

    static const U64 RookMagic[64];
    static const U64 BishopMagic[64];

    SMagic m_rook_tbl[SquareEnd];
    SMagic m_bishop_tbl[SquareEnd];

    U64 m_rook_table[64][4096];
    U64 m_bishop_table[64][512];

    U64 m_rook_occupancy[64][4096];
    U64 m_bishop_occupancy[64][512];

    U64 batt(int sq, U64 block);
    U64 ratt(int sq, U64 block);
    U64 bmask(int sq);
    U64 rmask(int sq);
    U64 set_occupancy(int index, int bits, U64 m);
    void _init_bitmasks();
    void _init_slider_masks_shifs_occupancies(int isRook);
    void _init_tables(int isRook);

  public:
    MagicBitboard();
    virtual ~MagicBitboard();

    U64 rook_attacks(U64 occ, SquareIndices sq);
    U64 bishop_attacks(U64 occ, SquareIndices sq);
    U64 queen_attacks(U64 occ, SquareIndices sq);
    int pop_1st_bit(U64* bb);
    int count_1s(U64 b);
};

#endif /* MAGIC_BITBOARD_H */
