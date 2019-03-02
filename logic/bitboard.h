#ifndef BITBOARD_H
#define BITBOARD_H

#include <string>
#include "../defs.h"
#include "piecesheaders.h"
#include "move.h"

typedef std::vector<Move> MoveList;

using std::string;

struct ExtMove {
  Move move;
  int value;

  operator Move() const { return move; }
  void operator=(Move m) { move = m; }
  void add(Move m) { move = m; }

  // Inhibit unwanted implicit conversions to Move
  // with an ambiguity that yields to a compile error.
  // operator float() const = delete;
};


class Bitboard {
 private:
   struct SMagic {
     U64* attacks;  // pointer to attack_table for each particular square
     U64 mask;  // to mask relevant squares of both lines (no outer squares)
     U64 magic;  // magic 64-bit factor
     int shift;  // shift right
   };

    U64 whitePawn_Attacks[64];
    U64 blackPawn_Attacks[64];
    U64 King_Attacks[64];
    U64 Knight_Attacks[64];

    U64 blackPawn_non_Attacks[64];
    U64 whitePawn_non_Attacks[64];

    U64 rookOccupancy[64][4096];
    U64 bishopOccupancy[64][512];
    U64 Bishop_Table[64][512];
    U64 Rook_Table[64][4096];

    SMagic mRookTbl[Squareend];
    SMagic mBishopTbl[Squareend];

    U64 SetMask[64];
    U64 ClearMask[64];
    U64 Enpessant[2];
    U64 notHFile = 0x7f7f7f7f7f7f7f7f;
    U64 notGHFile = 0x3f3f3f3f3f3f3f3f;
    U64 notAFile = 0xfefefefefefefefe;
    U64 notABFile = 0xfcfcfcfcfcfcfcfc;
    int boardScore = 0;
    // U64 pieces[13];
    // box *boardBB[64] = {nullptr};

    int CountBits(U64);
    int Popbit(U64 *);
    void _init_tables(int);
    void _init_slider_masks_shifs_occupancies(int);
    void _init_nonsliders_attacks();
    void _init_bitmasks();
    U64 batt(int sq, U64 block);
    U64 ratt(int sq, U64 block);
    U64 bmask(int sq);
    U64 rmask(int sq);
    int pop_1st_bit(U64 *bb);
    int count_1s(U64 b);
    U64 setOccupancy(int index, int bits, U64 m);
    U64 pawnMask(int sq, int side);
    U64 kingMask(int sq);
    U64 knightMask(int sq);
    U64 pawnNonAttack(int sq, int side);
    void gen_all_pawn_moves(string side, MoveList *);
    void gen_all_piece_moves(Piece* piece, MoveList *moveList);

 public:
    Bitboard();
    virtual ~Bitboard();
    void _init();

    U64& getAllWhitePos();
    U64& getAllBlackPos();
    U64 getPiecesBB(int pieceType);
    U64 bishopAttacks(U64 occ, SquareIndices);
    U64 rookAttacks(U64 occ, SquareIndices);
    U64 queenAttacks(U64 occ, SquareIndices);
    U64 getPieceAttacks(Piece *p, SquareIndices);
    U64 getNonAttackMoves(Piece *p, SquareIndices);
    void generateAllMoves(string side, MoveList*);
    void setBitAtWhitePieces(int pos);
    void setBitAtBlackPieces(int pos);
    void clearBitAtWhitePieces(int pos);
    void clearBitAtBlackPieces(int pos);
    void move(Piece* p, int f, int t);
    void capture_piece(Piece* piece, int pos);
    int evaluateBoard();
    void add_value(int value);

    Bishop blackBishop{"black", BISHOPSTART & ALLBLACKSTART};
    Bishop whiteBishop{"white", BISHOPSTART & ALLWHITESTART};

    King blackKing{"black", KINGSTART & ALLBLACKSTART};
    King whiteKing{"white", KINGSTART & ALLWHITESTART};

    Knight blackKnigth{"black", KNIGHTSTART & ALLBLACKSTART};
    Knight whiteKnigth{"white", KNIGHTSTART & ALLWHITESTART};

    Queen blackQueen{"black", QUEENSTART & ALLBLACKSTART};
    Queen whiteQueen{"white", QUEENSTART & ALLWHITESTART};

    Rook blackRook{"black", ROOKSTART & ALLBLACKSTART};
    Rook whiteRook{"white", ROOKSTART & ALLWHITESTART};

    Pawn blackPawn{"black", PAWNSTART & ALLBLACKSTART};
    Pawn whitePawn{"white", PAWNSTART & ALLWHITESTART};

    U64 m_allWhitePieces = ALLWHITESTART;
    U64 m_allBlackPieces = ALLBLACKSTART;
    U64 m_allPieces = ALLWHITESTART|ALLBLACKSTART;
};

#endif /* BITBOARD_H */
