#ifndef MAGIC_BITBOARD_H
#define MAGIC_BITBOARD_H

#include "utils/bit_utilities.h"

class MagicBitboard {
 private:
  struct SMagic {
    Bitboard *attacks;   // pointer to attack_table for each particular square
    // to mask relevant squares of both lines (no outer squares)
    Bitboard mask;
    Bitboard magic;   // magic 64-bit factor
    int shift;        // shift right
  };

  static const Bitboard RookMagic[64];
  static const Bitboard BishopMagic[64];

  SMagic m_rook_tbl[SquareEnd];
  SMagic m_bishop_tbl[SquareEnd];

  Bitboard m_rook_table[64][4096];
  Bitboard m_bishop_table[64][512];

  Bitboard m_rook_occupancy[64][4096];
  Bitboard m_bishop_occupancy[64][512];

  constexpr Bitboard batt(int sq, Bitboard block);
  constexpr Bitboard ratt(int sq, Bitboard block);
  constexpr Bitboard bmask(int sq);
  constexpr Bitboard rmask(int sq);
  Bitboard set_occupancy(int index, int bits, Bitboard m);
  void _init_bitmasks();
  void _init_slider_masks_shifs_occupancies(int isRook);
  void _init_tables(int isRook);

 public:
  MagicBitboard();
  virtual ~MagicBitboard();

  Bitboard rook_attacks(Bitboard occ, Square sq) const;
  Bitboard bishop_attacks(Bitboard occ, Square sq) const;
  Bitboard queen_attacks(Bitboard occ, Square sq) const;
};

class IMagicBitboardAttackType {
 public:
  virtual Bitboard get_attacks(Bitboard occ, Square sq) const = 0;

 protected:
  explicit IMagicBitboardAttackType(const MagicBitboard &mb)
      : m_magic_bitboard(&mb){};
  const MagicBitboard *const m_magic_bitboard;
};

class RookMagicBitboard : public IMagicBitboardAttackType {
 public:
  explicit RookMagicBitboard(const MagicBitboard &mb)
      : IMagicBitboardAttackType(mb) {}
  Bitboard get_attacks(Bitboard occ, Square sq) const {
    return m_magic_bitboard->rook_attacks(occ, sq);
  }
};

class BishopMagicBitboard : public IMagicBitboardAttackType {
 public:
  explicit BishopMagicBitboard(const MagicBitboard &mb)
      : IMagicBitboardAttackType(mb) {}
  Bitboard get_attacks(Bitboard occ, Square sq) const {
    return m_magic_bitboard->bishop_attacks(occ, sq);
  }
};

class QueenMagicBitboard : public IMagicBitboardAttackType {
 public:
  explicit QueenMagicBitboard(const MagicBitboard &mb)
      : IMagicBitboardAttackType(mb) {}
  Bitboard get_attacks(Bitboard occ, Square sq) const {
    return m_magic_bitboard->queen_attacks(occ, sq);
  }
};

#endif /* MAGIC_BITBOARD_H */
