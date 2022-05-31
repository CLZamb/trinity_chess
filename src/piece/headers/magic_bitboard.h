#ifndef MAGIC_BITBOARD_H
#define MAGIC_BITBOARD_H
#include <iostream>
#include "board/headers/bit_utilities.h"
#include <assert.h>

class MagicBitboard {
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

    constexpr U64 batt(int sq, U64 block);
    constexpr U64 ratt(int sq, U64 block);
    constexpr U64 bmask(int sq);
    constexpr U64 rmask(int sq);
    U64 set_occupancy(int index, int bits, U64 m);
    void _init_bitmasks();
    void _init_slider_masks_shifs_occupancies(int isRook);
    void _init_tables(int isRook);

 public:
    MagicBitboard();
    virtual ~MagicBitboard();

    U64 rook_attacks(U64 occ, SquareIndices sq) const;
    U64 bishop_attacks(U64 occ, SquareIndices sq) const;
    U64 queen_attacks(U64 occ, SquareIndices sq) const;
};

class IMagicBitboardAttackType {
  public:
    virtual U64 get_attacks(U64 occ, SquareIndices sq) const = 0;

  protected:
    IMagicBitboardAttackType(const MagicBitboard& mb) : m_magic_bitboard(&mb) {};
    virtual ~IMagicBitboardAttackType() = default;
    const MagicBitboard* const m_magic_bitboard;
};

class RookMagicBitboard : public IMagicBitboardAttackType {
  public:
    RookMagicBitboard(const MagicBitboard& mb) : IMagicBitboardAttackType(mb) {}
    U64 get_attacks(U64 occ, SquareIndices sq) const {
      return m_magic_bitboard->rook_attacks(occ, sq);
    }
};

class BishopMagicBitboard : public IMagicBitboardAttackType {
  public:
    BishopMagicBitboard(const MagicBitboard& mb) : IMagicBitboardAttackType(mb) {}
    U64 get_attacks(U64 occ, SquareIndices sq) const {
      return m_magic_bitboard->bishop_attacks(occ, sq);
    }
};

class QueenMagicBitboard : public IMagicBitboardAttackType {
  public:
    QueenMagicBitboard(const MagicBitboard& mb) : IMagicBitboardAttackType(mb) {}
    U64 get_attacks(U64 occ, SquareIndices sq) const {
      return m_magic_bitboard->queen_attacks(occ, sq);
    }
};

#endif /* MAGIC_BITBOARD_H */
