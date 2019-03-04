#ifndef BITBOARD_H
#define BITBOARD_H

#include <string>
#include "piecesheaders.h"
#include "move.h"

typedef std::vector<Move> MoveList;

using std::string;

struct ExtMove {
  Move m_move;
  int value;

  operator Move() const { return m_move; }
  void operator=(Move m) { m_move = m; }
  void add(Move m) { m_move = m; }

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

    U64 m_w_pawn_attacks[64];
    U64 m_b_pawn_attacks[64];
    U64 m_knight_attacks[64];
    U64 m_king_attacks[64];

    U64 m_b_pawn_non_attacks[64];
    U64 m_w_pawn_non_attacks[64];

    U64 m_rook_occupancy[64][4096];
    U64 m_bishop_occupancy[64][512];
    U64 m_bishop_table[64][512];
    U64 m_rook_table[64][4096];

    SMagic m_rook_tbl[Squareend];
    SMagic m_bishop_tbl[Squareend];

    U64 SetMask[64];
    U64 ClearMask[64];
    U64 Enpessant[2];
    int board_score = 0;
    // U64 pieces[13];
    // box *boardBB[64] = {nullptr};

    int CountBits(U64);
    int Popbit(U64*);
    void _init_tables(int);
    void _init_slider_masks_shifs_occupancies(int);
    void _init_nonsliders_attacks();
    void _init_bitmasks();
    U64 batt(int sq, U64 block);
    U64 ratt(int sq, U64 block);
    U64 bmask(int sq);
    U64 rmask(int sq);
    int pop_1st_bit(U64* bb);
    int count_1s(U64 b);
    U64 set_occupancy(int index, int bits, U64 m);
    U64 pawn_mask(int sq, int side);
    U64 knight_mask(int sq);
    U64 king_mask(int sq);
    U64 pawn_non_attack(int sq, int side);
    void gen_all_pawn_moves(Piece* piece, MoveList*);
    void gen_all_piece_moves(Piece* piece, MoveList* moveList);

 public:
    Bitboard();
    virtual ~Bitboard();
    void _init();

    U64& get_all_w_bitboard();
    U64& get_all_b_bitboard();
    U64 get_Pieces_BB(int piece_type);
    U64 bishop_attacks(U64 occ, SquareIndices);
    U64 rook_attacks(U64 occ, SquareIndices);
    U64 queen_attacks(U64 occ, SquareIndices);
    U64 get_piece_attacks(Piece* p, SquareIndices);
    U64 get_non_attack_moves(Piece* p, SquareIndices);
    void generate_all_moves(bool side, MoveList*);
    void set_bit_at_w_pieces(int pos);
    void set_bit_at_b_pieces(int pos);
    void clear_bit_at_w_pieces(int pos);
    void clear_bit_at_b_pieces(int pos);
    void move(Piece* p, int f, int t);
    void capture_piece(Piece* piece, int pos);
    void add_value(int value);
    int evaluate_board();

    Bishop m_b_bishop{BLACK, BISHOPSTART & ALLBLACKSTART};
    Bishop m_w_bishop{WHITE, BISHOPSTART & ALLWHITESTART};

    King m_b_king{BLACK, KINGSTART & ALLBLACKSTART};
    King m_w_king{WHITE, KINGSTART & ALLWHITESTART};

    Knight m_b_knigth{BLACK, KNIGHTSTART & ALLBLACKSTART};
    Knight m_w_knigth{WHITE, KNIGHTSTART & ALLWHITESTART};

    Queen m_b_queen{BLACK, QUEENSTART & ALLBLACKSTART};
    Queen m_w_queen{WHITE, QUEENSTART & ALLWHITESTART};

    Rook m_b_rook{BLACK, ROOKSTART & ALLBLACKSTART};
    Rook m_w_rook{WHITE, ROOKSTART & ALLWHITESTART};

    Pawn m_b_pawn{BLACK, PAWNSTART & ALLBLACKSTART};
    Pawn m_w_pawn{WHITE, PAWNSTART & ALLWHITESTART};

    U64 m_all_w_pieces = ALLWHITESTART;
    U64 m_all_b_pieces = ALLBLACKSTART;
    U64 m_all_pieces = ALLWHITESTART|ALLBLACKSTART;
};

#endif /* BITBOARD_H */
