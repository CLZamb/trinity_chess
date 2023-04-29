#ifndef BIT_UTILITIES_H
#define BIT_UTILITIES_H

#include "board/position/position_typedefs.h"
#include "defs.h"
#include <iostream>

namespace bitUtility {
  inline Bitboard set_mask_bb(Square s) {
    return SetMask[s];
  }

  inline Bitboard clear_mask_bb(Square s) {
    return ClearMask[s];
  }

  inline void set_bit(Bitboard* bb, Square s) {
    *bb |= (1ULL << s);
  }

  inline void clear_bit(Bitboard* bb, Square s) {
    *bb &= clear_mask_bb(s);
  }

  inline int count_1s(Bitboard b) {
    static int r = 0;
    for (r = 0; b; r++, b &= b - 1) {}
    return r;
  }

  inline int pop_1st_bit(Bitboard* bb) {
    Bitboard b = *bb ^ (*bb - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    *bb &= (*bb - 1);
    return BitTable[(fold * 0x783a9b23) >> 26];
  }

  inline void printBitBoard(Bitboard bb) {
    Bitboard shift = 1ULL;
    int rank = 0;
    int file = 0;
    int position = 0;

    std::cout << '\n';
    for (rank = 7; rank >= 0; --rank) {
      for (file = 0; file <= 7; ++file) {
        position = rank * 8 + file;

        if ((shift << position) & bb)
          std::cout << "X";
        else
          std::cout << "-";
      }

      std::cout << '\n';
    }
    std::cout << "\n\n";
  }

  /***********************************************************
   * Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
   * Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
   * Copyright (C) 2015-2019 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
   * Stockfish, a UCI chess playing engine derived from Glaurung 2.1
   *************************************************************/
  enum Direction : int {
    NORTH =  8,
    EAST  =  1,
    SOUTH = -NORTH,
    WEST  = -EAST,

    NORTH_NORTH = NORTH + NORTH,
    SOUTH_SOUTH = SOUTH + SOUTH,
    NORTH_EAST = NORTH + EAST,
    SOUTH_EAST = SOUTH + EAST,
    SOUTH_WEST = SOUTH + WEST,
    NORTH_WEST = NORTH + WEST
  };

  /***********************************************************
   * Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
   * Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
   * Copyright (C) 2015-2019 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
   * Stockfish, a UCI chess playing engine derived from Glaurung 2.1
   *************************************************************/
  constexpr Bitboard FileABB = 0x0101010101010101ULL;
  constexpr Bitboard FileHBB = FileABB << 7;
  /// shift() moves a bitboard one step along direction D
  template<Direction D>
    constexpr Bitboard shift(Bitboard b) {
      return  D == NORTH  ?  b             << 8 : D == SOUTH      ?  b             >> 8
        : D == NORTH+NORTH?  b             <<16 : D == SOUTH+SOUTH?  b             >>16
        : D == EAST       ? (b & ~FileHBB) << 1 : D == WEST       ? (b & ~FileABB) >> 1
        : D == NORTH_EAST ? (b & ~FileHBB) << 9 : D == NORTH_WEST ? (b & ~FileABB) << 7
        : D == SOUTH_EAST ? (b & ~FileHBB) >> 7 : D == SOUTH_WEST ? (b & ~FileABB) >> 9
        : 0;
    }
}  // namespace bitUtility

#endif /* BIT_UTILITIES_H */
