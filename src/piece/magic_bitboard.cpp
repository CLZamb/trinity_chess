#include "headers/magic_bitboard.h"
#include "../board/headers/defs.h"

// extern declaration in defs.h
U64 SetMask[64];
U64 ClearMask[64];
// define in magic_bitboard.cpp - _init_bitmasks()

// Magic_Bitboards() computes all rook and bishop attacks at startup. Magic
// bitboards are used to look up attacks of sliding pieces. As a reference see
// www.chessprogramming.org/Magic_Bitboards. In particular, here we use the so
// called "fancy" approach.
MagicBitboard::MagicBitboard() {
  int Rook = 1, Bishop = 0;
  _init_bitmasks();
  _init_slider_masks_shifs_occupancies(Bishop);
  _init_slider_masks_shifs_occupancies(Rook);
  _init_tables(Bishop);
  _init_tables(Rook);
}

MagicBitboard::~MagicBitboard() {}

constexpr U64 MagicBitboard::RookMagic[64] = {
  0x2380004000201080ULL, 0x2040100020004001ULL, 0x180086002100080ULL, 0x4080048008021000ULL,
  0xa00086004100200ULL, 0x80018004004200ULL, 0x400640810030082ULL, 0x4280014100102080ULL,
  0x80a002600450080ULL, 0x4005004004802100ULL, 0x81004104102000ULL, 0x3441000921021000ULL,
  0x2002010460008ULL, 0x806001004020008ULL, 0x3541002100140200ULL, 0x25000260810002ULL,
  0x800040042002d2ULL, 0x10104000442000ULL, 0x50028010802000ULL, 0xf0008028001080ULL,
  0x8008008040080ULL, 0x10100080c0002ULL, 0xa00040002010890ULL, 0xa42020000670084ULL,
  0xc80084040002000ULL, 0x200640005006ULL, 0x51410100200091ULL, 0x101c900201000ULL,
  0x21080100050010ULL, 0x242001200190410ULL, 0x1a1400081011ULL, 0x1204200140091ULL,
  0x1000400020800088ULL, 0x1100442000401000ULL, 0x204102001004100ULL, 0x4006102202004008ULL,
  0x28010400800881ULL, 0x80100040100081eULL, 0x101100e24000148ULL, 0x44004412000981ULL,
  0x480094220084000ULL, 0x10200050024002ULL, 0x61002000110042ULL, 0x5005001890021ULL,
  0x8010500090010ULL, 0x9000864010002ULL, 0x501100142440008ULL, 0x12a040040820001ULL,
  0xa44408209002200ULL, 0x1010084000200040ULL, 0x208012004200ULL, 0x2243001001900ULL,
  0x1022000810042200ULL, 0x1c22000830040600ULL, 0x800100508220400ULL, 0x1000a44820300ULL,
  0x81430110800021ULL, 0x80401100260082ULL, 0x2001010830c1ULL, 0x200210049045001ULL,
  0x42060088209c3042ULL, 0x700a604001811ULL, 0x80201100084ULL, 0x168004a21040086ULL
};

constexpr U64 MagicBitboard::BishopMagic[64] = {
  0x4151002060840ULL, 0x403060403020001ULL, 0x1800c400800010ULL, 0x2848c100080024ULL,
  0x84050420e00001ULL, 0x4406090460180001ULL, 0x4014120846090024ULL, 0x4808150c01044004ULL,
  0x40448020400ULL, 0x100850a2020400b4ULL, 0x4042440800810080ULL, 0x7092440c02805000ULL,
  0x200040308220000ULL, 0xe08420804e6ULL, 0x100020801043008ULL, 0x1801021200822800ULL,
  0x10002002624800ULL, 0x308001202081202ULL, 0x480800c418011010ULL, 0x822000406120001ULL,
  0x204000822080560ULL, 0x4004082202020200ULL, 0x2012010c48140408ULL, 0x2021000022982400ULL,
  0x20080110100103ULL, 0x14200010110100ULL, 0x204808100b014100ULL, 0x20090080040c0ULL,
  0x4001010040104011ULL, 0x3910a00040a0111ULL, 0x4005140002c20820ULL, 0x5243020001055102ULL,
  0x2002084050041000ULL, 0x24a02202c300124ULL, 0x2882030102900041ULL, 0x10510801040040ULL,
  0x4000404040440100ULL, 0x1008050102080880ULL, 0x410800a401010100ULL, 0x2004211240062410ULL,
  0x22d11301004401cULL, 0x582828010c04ULL, 0xa10140024020808ULL, 0xc20004200800800ULL,
  0x4202022a000400ULL, 0x414112020e000c10ULL, 0x100441940c000509ULL, 0xa102c0440c10080ULL,
  0x4081010802411801ULL, 0x414404404200001ULL, 0x20004c4454100801ULL, 0x810000a10440000ULL,
  0x80080803040804ULL, 0x540408020000ULL, 0x1020200202004820ULL, 0x484108200510230ULL,
  0x600e010051042020ULL, 0x4404880880ULL, 0x428044044400ULL, 0x1400000208420202ULL,
  0x4000004004904400ULL, 0x10200a1408104101ULL, 0x48004002184200a0ULL, 0x2041000850100ULL
};

void MagicBitboard::_init_bitmasks() {
  for (int i = 0; i < 64; ++i) {
    SetMask[i] = 0ULL;
    ClearMask[i] = 0ULL;
  }

  for (int i = 0; i < 64; ++i) {
    SetMask[i] |= (1ULL << i);
    ClearMask[i] = ~SetMask[i];
  }

  for (int sq = 0; sq < 64; ++sq) {
    m_rook_tbl[sq].magic = RookMagic[sq];
    m_bishop_tbl[sq].magic = BishopMagic[sq];
  }
}

U64 MagicBitboard::rook_attacks(U64 occ, SquareIndices sq) const {
  // U64* aptr = m_rook_tbl[sq].ptr;
  occ &= m_rook_tbl[sq].mask;
  occ *=  m_rook_tbl[sq].magic;
  occ >>= m_rook_tbl[sq].shift;

  assert(occ < 4096);
  return m_rook_table[sq][occ];
}

U64 MagicBitboard::bishop_attacks(U64 occ, SquareIndices sq) const {
  // U64* aptr = m_bishop_tbl[sq].ptr;
  occ &= m_bishop_tbl[sq].mask;
  occ *= m_bishop_tbl[sq].magic;
  occ >>=  m_bishop_tbl[sq].shift;
  return m_bishop_table[sq][occ];
}

U64 MagicBitboard::queen_attacks(U64 occ, SquareIndices sq) const {
  U64 result = 0ULL;
  U64 temp_occ = occ;

  occ &= m_bishop_tbl[sq].mask;
  occ *= m_bishop_tbl[sq].magic;
  occ >>=  m_bishop_tbl[sq].shift;

  result = m_bishop_table[sq][occ];

  temp_occ &= m_rook_tbl[sq].mask;
  temp_occ *= m_rook_tbl[sq].magic;
  temp_occ >>= m_rook_tbl[sq].shift;

  result |= m_rook_table[sq][temp_occ];
  return result;
}


constexpr U64 MagicBitboard::rmask(int sq) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8;
  int r = rk + 1, f = fl + 1;
  for (r = rk+1; r <= 6; r++) result |= (1ULL << (fl + r*8));
  for (r = rk-1; r >= 1; r--) result |= (1ULL << (fl + r*8));
  for (f = fl+1; f <= 6; f++) result |= (1ULL << (f + rk*8));
  for (f = fl-1; f >= 1; f--) result |= (1ULL << (f + rk*8));
  return result;
}

constexpr U64 MagicBitboard::bmask(int sq) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8;
  int r = rk + 1, f = fl + 1;
  for (r = rk+1, f=fl+1; r <= 6 && f <= 6; r++, f++)
    result |= (1ULL << (f + r*8));
  for (r = rk+1, f=fl-1; r <= 6 && f >= 1; r++, f--)
    result |= (1ULL << (f + r*8));
  for (r = rk-1, f=fl+1; r >= 1 && f <= 6; r--, f++)
    result |= (1ULL << (f + r*8));
  for (r = rk-1, f=fl-1; r >= 1 && f >= 1; r--, f--)
    result |= (1ULL << (f + r*8));
  return result;
}

constexpr U64 MagicBitboard::ratt(int sq, U64 block) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8;
  int r = rk + 1, f = fl + 1;
  for (r = rk+1; r <= 7; r++) {
    result |= (1ULL << (fl + r*8));
    if (block & (1ULL << (fl + r*8))) break;
  }
  for (r = rk-1; r >= 0; r--) {
    result |= (1ULL << (fl + r*8));
    if (block & (1ULL << (fl + r*8))) break;
  }
  for (f = fl+1; f <= 7; f++) {
    result |= (1ULL << (f + rk*8));
    if (block & (1ULL << (f + rk*8))) break;
  }
  for (f = fl-1; f >= 0; f--) {
    result |= (1ULL << (f + rk*8));
    if (block & (1ULL << (f + rk*8))) break;
  }
  return result;
}

constexpr U64 MagicBitboard::batt(int sq, U64 block) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8;
  int r = rk + 1, f = fl + 1;
  for (r = rk+1, f = fl+1; r <= 7 && f <= 7; r++, f++) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  for (r = rk+1, f = fl-1; r <= 7 && f >= 0; r++, f--) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  for (r = rk-1, f = fl+1; r >= 0 && f <= 7; r--, f++) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  for (r = rk-1, f = fl-1; r >= 0 && f >= 0; r--, f--) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  return result;
}

U64 MagicBitboard::set_occupancy(int index, int bits, U64 m) {
  int i, j;
  U64 result = 0ULL;

  for (i = 0; i < bits; i++) {
    j = bitUtility::pop_1st_bit(&m);
    if (index & (1 << i))
      result |= (1ULL << j);
  }

  return result;
}

void MagicBitboard::_init_slider_masks_shifs_occupancies(int isRook) {
  int i, bitCount, variationCount;
  U64 mask;

  for (int bitRef = A1; bitRef < SquareEnd; ++bitRef) {
    m_rook_tbl[bitRef].mask = rmask(bitRef);
    m_bishop_tbl[bitRef].mask = bmask(bitRef);
    m_rook_tbl[bitRef].shift = 64 - RBits[bitRef];
    m_bishop_tbl[bitRef].shift = 64 - BBits[bitRef];
    mask = isRook ? m_rook_tbl[bitRef].mask : m_bishop_tbl[bitRef].mask;
    bitCount = bitUtility::count_1s(mask);
    variationCount = 1 << bitCount;
    for (i = 0; i < variationCount; i++) {
      if (isRook) {
        m_rook_occupancy[bitRef][i] = 0ULL;
        m_rook_occupancy[bitRef][i] = set_occupancy(i, bitCount, mask);
      } else {
        m_bishop_occupancy[bitRef][i] = 0ULL;
        m_bishop_occupancy[bitRef][i] = set_occupancy(i, bitCount, mask);
      }
    }
  }
}

void MagicBitboard::_init_tables(int isRook) {
  U64 validMoves, mask;
  int variations, bitCount;
  int i, magicIndex;

  for (int bitRef = A1; bitRef < SquareEnd; ++bitRef) {
    mask = isRook ? m_rook_tbl[bitRef].mask : m_bishop_tbl[bitRef].mask;
    bitCount = bitUtility::count_1s(mask);
    variations = 1ULL << bitCount;

    for (i=0; i < variations; i++) {
      if (isRook) {
        validMoves = ratt(bitRef, m_rook_occupancy[bitRef][i]);
        magicIndex = m_rook_occupancy[bitRef][i] *
          m_rook_tbl[bitRef].magic >> m_rook_tbl[bitRef].shift;

        m_rook_table[bitRef][magicIndex] = validMoves;
      } else {
        validMoves = batt(bitRef, m_bishop_occupancy[bitRef][i]);
        magicIndex = m_bishop_occupancy[bitRef][i] *
          m_bishop_tbl[bitRef].magic >> m_bishop_tbl[bitRef].shift;

        m_bishop_table[bitRef][magicIndex] = validMoves;
      }
    }
  }
}
