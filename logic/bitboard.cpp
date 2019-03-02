#include "bitboard.h"
Bitboard::Bitboard() {}
Bitboard::~Bitboard() {}

void Bitboard::_init() {
  int Rook = 1, Bishop = 0;
  _init_bitmasks();
  _init_nonsliders_attacks();
  _init_slider_masks_shifs_occupancies(Bishop);
  _init_slider_masks_shifs_occupancies(Rook);
  _init_tables(Bishop);
  _init_tables(Rook);
}

void Bitboard::_init_nonsliders_attacks() {
  int sq;

  int white= 0, black = 1;
  for (sq = 0; sq < 64; sq++) {
    whitePawn_Attacks[sq] = pawnMask(sq, white);
    blackPawn_Attacks[sq] = pawnMask(sq, black);
    Knight_Attacks[sq] = knightMask(sq);
    King_Attacks[sq] = kingMask(sq);
    whitePawn_non_Attacks[sq] = pawnNonAttack(sq, white);
    blackPawn_non_Attacks[sq] = pawnNonAttack(sq, black);
  }
}

void Bitboard::_init_bitmasks() {
  for (int i = 0; i < 64; ++i) {
    SetMask[i] = 0ULL;
    ClearMask[i] = 0ULL;
  }

  for (int i = 0; i < 64; ++i) {
    SetMask[i] |= (1ULL << i);
    ClearMask[i] = ~SetMask[i];
  }

  for (int sq = 0; sq < 64; ++sq) {
    mBishopTbl[sq].magic = BishopMagic[sq];
    mRookTbl[sq].magic = RookMagic[sq];
  }
}

int Bitboard::count_1s(U64 b) {
  int r;
  for (r = 0; b; r++, b &= b - 1) {}
  return r;
}

int Bitboard::pop_1st_bit(U64 *bb) {
  U64 b = *bb ^ (*bb - 1);
  unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
  *bb &= (*bb - 1);
  return BitTable[(fold * 0x783a9b23) >> 26];
}

U64 Bitboard::rmask(int sq) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
  for (r = rk+1; r <= 6; r++) result |= (1ULL << (fl + r*8));
  for (r = rk-1; r >= 1; r--) result |= (1ULL << (fl + r*8));
  for (f = fl+1; f <= 6; f++) result |= (1ULL << (f + rk*8));
  for (f = fl-1; f >= 1; f--) result |= (1ULL << (f + rk*8));
  return result;
}

U64 Bitboard::bmask(int sq) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
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

U64 Bitboard::ratt(int sq, U64 block) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
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

U64 Bitboard::batt(int sq, U64 block) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
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

U64 Bitboard::bishopAttacks(U64 occ, SquareIndices sq) {
  // U64* aptr = mBishopTbl[sq].ptr;
  occ &= mBishopTbl[sq].mask;
  occ *= mBishopTbl[sq].magic;
  occ >>= mBishopTbl[sq].shift;
  return Bishop_Table[sq][occ];
}

U64 Bitboard::rookAttacks(U64 occ, SquareIndices sq) {
  // U64* aptr = mRookTbl[sq].ptr;
  occ &= mRookTbl[sq].mask;
  occ *=  mRookTbl[sq].magic;
  occ >>= mRookTbl[sq].shift;
  return Rook_Table[sq][occ];
}

U64 Bitboard::queenAttacks(U64 occ, SquareIndices sq) {
  U64 result = 0ULL;
  U64 temp_occ = occ;

  occ &= mBishopTbl[sq].mask;
  occ *= mBishopTbl[sq].magic;
  occ >>= mBishopTbl[sq].shift;

  result = Bishop_Table[sq][occ];

  temp_occ &= mRookTbl[sq].mask;
  temp_occ *=  mRookTbl[sq].magic;
  temp_occ >>= mRookTbl[sq].shift;

  result |= Rook_Table[sq][temp_occ];

  return result;
}

U64 Bitboard::pawnNonAttack(int sq, int side) {
  int white = 0;
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (side == white) {
    if (fromSq << 8)
      result |= fromSq << 8;

    if (fromSq << 16)
      result |= (fromSq & ROWMASK[1]) << 16;
  } else {
    if (fromSq >> 8)
      result |= fromSq >> 8;

    if (fromSq >> 16)
      result |= (fromSq & ROWMASK[6]) >> 16;
  }

  return result;
}

U64 Bitboard::pawnMask(int sq, int side) {
  int white = 0;
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (side == white) {
    if (fromSq << 7 & notHFile)
      result |= fromSq << 7;

    if (fromSq << 9 & notAFile)
      result |= fromSq << 9;
  } else {
    if (fromSq >> 7 & notAFile)
      result |= fromSq >> 7;

    if (fromSq >> 9 & notHFile)
      result |= fromSq >> 9;
  }

  return result;
}

U64 Bitboard::kingMask(int sq) {
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (fromSq >> 1 & notHFile)
    result |= fromSq >> 1 & notHFile;

  if (fromSq << 1 & notAFile)
    result |= fromSq << 1 & notAFile;

  if (fromSq >> 7 & notAFile)
    result |= fromSq >> 7 & notAFile;

  if (fromSq << 7 & notHFile)
    result |= fromSq << 7 & notHFile;

  if (fromSq >> 8)
    result |= fromSq >> 8;

  if (fromSq << 8)
    result |= fromSq << 8;

  if (fromSq >> 9 & notHFile)
    result |= fromSq >> 9 & notHFile;

  if (fromSq << 9 & notAFile)
    result |= fromSq << 9 & notAFile;

  return result;
}

U64 Bitboard::knightMask(int sq) {
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (fromSq >> 17 & notHFile)
    result |= fromSq >> 17 & notHFile;

  if (fromSq >> 15 & notAFile)
    result |= fromSq >> 15 & notAFile;

  if (fromSq >> 10 & notGHFile)
    result |= fromSq >> 10 & notGHFile;

  if (fromSq >> 6 & notABFile)
    result |= fromSq >> 6 & notABFile;

  if (fromSq << 17 & notAFile)
    result |= fromSq << 17 & notAFile;

  if (fromSq << 15 & notHFile)
    result |= fromSq << 15 & notHFile;

  if (fromSq << 10 & notABFile)
    result |= fromSq << 10 & notABFile;

  if (fromSq << 6 & notGHFile)
    result |= fromSq << 6 & notGHFile;

  return result;
}

U64 Bitboard::setOccupancy(int index, int bits, U64 m) {
  int i, j;
  U64 result = 0ULL;

  for (i = 0; i < bits; i++) {
    j = pop_1st_bit(&m);
    if (index & (1 << i))
      result |= (1ULL << j);
  }

  return result;
}

void Bitboard::_init_slider_masks_shifs_occupancies(int isRook) {
  int i, bitCount, variationCount;
  U64 mask;

  for (int bitRef = A1; bitRef < Squareend; ++bitRef) {
    mRookTbl[bitRef].mask = rmask(bitRef);
    mBishopTbl[bitRef].mask = bmask(bitRef);
    mRookTbl[bitRef].shift = 64 - RBits[bitRef];
    mBishopTbl[bitRef].shift = 64 - BBits[bitRef];
    mask = isRook ?  mRookTbl[bitRef].mask : mBishopTbl[bitRef].mask;
    bitCount = count_1s(mask);
    variationCount = 1 << bitCount;
    for (i = 0; i < variationCount; i++) {
      if (isRook) {
        rookOccupancy[bitRef][i] = 0ULL;
        rookOccupancy[bitRef][i] = setOccupancy(i, bitCount, mask);
      } else {
        bishopOccupancy[bitRef][i] = 0ULL;
        bishopOccupancy[bitRef][i] = setOccupancy(i, bitCount, mask);
      }
    }
  }
}

void Bitboard::_init_tables(int isRook) {
  U64 validMoves, mask;
  int variations, bitCount;
  int bitRef, i, magicIndex;

  for (int bitRef = A1; bitRef < Squareend; ++bitRef) {
    mask = isRook ? mRookTbl[bitRef].mask : mBishopTbl[bitRef].mask;
    bitCount = count_1s(mask);
    variations = 1ULL << bitCount;

    for (i=0; i < variations; i++) {
      if (isRook) {
        validMoves = ratt(bitRef, rookOccupancy[bitRef][i]);
        magicIndex = rookOccupancy[bitRef][i] *
          mRookTbl[bitRef].magic >> mRookTbl[bitRef].shift;
        Rook_Table[bitRef][magicIndex] = validMoves;
      } else {
        validMoves = batt(bitRef, bishopOccupancy[bitRef][i]);
        magicIndex = bishopOccupancy[bitRef][i]
          * mBishopTbl[bitRef].magic >> mBishopTbl[bitRef].shift;
        Bishop_Table[bitRef][magicIndex] = validMoves;
      }
    }
  }
}

U64 Bitboard::getNonAttackMoves(Piece* piece, SquareIndices from) {
  if (piece->getPieceType() != "pawn")
    return BLANK;

  if (piece->getColorPiece() == "white")
    return whitePawn_non_Attacks[from] & ~m_allPieces;

  return blackPawn_non_Attacks[from] & ~m_allPieces;
}

U64 Bitboard::getPieceAttacks(Piece* piece, SquareIndices from) {
  string type = piece->getPieceType();
  if (type == "pawn") {
    if (piece->getColorPiece() == "white") {
      return whitePawn_Attacks[from] & m_allBlackPieces;
    }

    return blackPawn_Attacks[from] & m_allWhitePieces;
  } else if (type == "rook")
    return rookAttacks(m_allPieces, from);
  else if (type == "queen")
    return queenAttacks(m_allPieces, from);
  else if (type == "king")
    return King_Attacks[from];
  else if (type == "bishop")
    return bishopAttacks(m_allPieces, from);
  else if (type == "knight")
    return Knight_Attacks[from];
  else
    return ZERO;
}

void Bitboard::gen_all_pawn_moves(string side, MoveList *moveList) {
  U64 toPos = BLANK, fromPos = BLANK;
  int i = 0;

  if (side == "black") {
    fromPos = blackPawn.getPieceBB();
    while (fromPos) {
      i = pop_1st_bit(&fromPos);
      toPos = getPieceAttacks(&blackPawn, SquareIndices(i));
      toPos |= getNonAttackMoves(&blackPawn, SquareIndices(i));
      while (toPos)
        moveList->push_back(Move(i, pop_1st_bit(&toPos), 0));
    }
  } else {
    fromPos = whitePawn.getPieceBB();
    while (fromPos) {
      i = pop_1st_bit(&fromPos);
      toPos = getPieceAttacks(&whitePawn, SquareIndices(i));
      toPos |= getNonAttackMoves(&whitePawn, SquareIndices(i));
      while (toPos)
        moveList->push_back(Move(i, pop_1st_bit(&toPos), 0));
    }
  }
}

void Bitboard::gen_all_piece_moves(Piece* piece, MoveList *moveList) {
  U64 toPos = BLANK, fromPos = BLANK;
  int i = 0;

  fromPos = piece->getPieceBB();
  while (fromPos) {
    i = pop_1st_bit(&fromPos);
    toPos = getPieceAttacks(piece, SquareIndices(i));
    while (toPos)
      moveList->push_back(Move(i, pop_1st_bit(&toPos), 0));
  }
}

void Bitboard::generateAllMoves(string side, MoveList *moveList) {
  gen_all_piece_moves(side == "black"? &blackKnigth : &whiteKnigth, moveList);
  gen_all_pawn_moves(side, moveList);
  gen_all_piece_moves(side == "black"? &blackRook : &whiteRook, moveList);
  gen_all_piece_moves(side == "black"? &blackBishop : &whiteBishop, moveList);
  gen_all_piece_moves(side == "black"? &blackQueen : &whiteQueen, moveList);
  gen_all_piece_moves(side == "black"? &blackKing : &whiteKing, moveList);
}

void Bitboard::setBitAtWhitePieces(int pos) {
  SETBIT(m_allWhitePieces, pos);
  SETBIT(m_allPieces, pos);
}

void Bitboard::setBitAtBlackPieces(int pos) {
  SETBIT(m_allBlackPieces, pos);
  SETBIT(m_allPieces, pos);
}

void Bitboard::clearBitAtWhitePieces(int pos) {
  CLRBIT(m_allWhitePieces, pos);
  CLRBIT(m_allPieces, pos);
}

void Bitboard::clearBitAtBlackPieces(int pos) {
  CLRBIT(m_allBlackPieces, pos);
  CLRBIT(m_allPieces, pos);
}

void Bitboard::move(Piece* piece, int from, int to) {
  piece->make_move(from, to);
  if (piece->getColorPiece() == "black") {
    clearBitAtBlackPieces(from);
    setBitAtBlackPieces(to);
  } else {
    clearBitAtWhitePieces(from);
    setBitAtWhitePieces(to);
  }
}

U64& Bitboard::getAllWhitePos() { return m_allWhitePieces; }
U64& Bitboard::getAllBlackPos() { return m_allBlackPieces; }
void Bitboard::capture_piece(Piece* piece, int pos) {
  piece->clearBit(pos);
  if (piece->getColorPiece() == "black")
    clearBitAtBlackPieces(pos);
  else
    clearBitAtWhitePieces(pos);

  boardScore -= piece->getValue();
}

void Bitboard::add_value(int value) { boardScore += value; }
int Bitboard::evaluateBoard() {
  return boardScore;
}
