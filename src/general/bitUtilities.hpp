#ifndef BITUTILITIES_H
#define BITUTILITIES_H

#include "defs.h"

namespace bitUtility {
  inline U64 set_mask_bb(SquareIndices s) {
    return SetMask[s];
  }

  inline U64 clear_mask_bb(SquareIndices s) {
    return ClearMask[s];
  }

  inline void set_bit(U64* bb, SquareIndices s) {
    *bb |= set_mask_bb(s);
  }

  inline void clear_bit(U64* bb, SquareIndices s) {
    *bb &= clear_mask_bb(s);
  }

  inline int count_1s(U64 b) {
    static int r = 0;
    for (r = 0; b; r++, b &= b - 1) {}
    return r;
  }

  inline int pop_1st_bit(U64* bb) {
    U64 b = *bb ^ (*bb - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    *bb &= (*bb - 1);
    return BitTable[(fold * 0x783a9b23) >> 26];
  }
}  // namespace bitUtility

#endif /* BITUTILITIES_H */
