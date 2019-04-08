#ifndef BITBOARD_H
#define BITBOARD_H

#include <string>
#include "piecesheaders.h"
#include "move.h"

using std::string;

typedef std::vector<Move> MoveList;

class Bitboard {
 private:
    struct SMagic {
      U64* attacks;  // pointer to attack_table for each particular square
      U64 mask;  // to mask relevant squares of both lines (no outer squares)
      U64 magic;  // magic 64-bit factor
      int shift;  // shift right
    };

    int ply = 0;
    int board_score = 0;
    int pieces_score[13][64] = {{0}};
    int MvvLvaScores[13][13];
    int search_history[13][64] = {{0}};
    static const int MAXDEPTH = 64;
    Move killers[2][MAXDEPTH];

    SMagic m_rook_tbl[Squareend];
    SMagic m_bishop_tbl[Squareend];

    U64 m_all_w_pieces = ALLWHITESTART;
    U64 m_all_b_pieces = ALLBLACKSTART;
    U64 m_all_pieces = ALLWHITESTART|ALLBLACKSTART;

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

    U64 SetMask[64];
    U64 ClearMask[64];
    U64 Enpessant[2];

    Piece* m_pieces[13];

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

    int pop_1st_bit(U64* bb);
    int count_1s(U64 b);
    void _init_bitmasks();
    void _init_nonsliders_attacks();
    void _init_pieces();
    void _init_pieces_table_values();
    void _init_slider_masks_shifs_occupancies(int);
    void _init_tables(int);
    void _init_MvvLva();
    void gen_all_pawn_moves(int type, MoveList*);
    void gen_all_piece_moves(int type, MoveList* moveList);
    void gen_all_captured_moves(U64 dest, Move mv, MoveList* moveList);
    void gen_all_quiet_moves(U64 dest, Move mv, MoveList* moveList);
    void set_bit_at_player_pieces(bool is_black, int pos);
    void add_quiet_move(Move quiet_move, MoveList* move_list);
    void add_captured_move(Move capture_move, MoveList* move_list);
    void add_en_pessant_move(Move ep_move, MoveList* move_list);
    U64 batt(int sq, U64 block);
    U64 ratt(int sq, U64 block);
    U64 bmask(int sq);
    U64 rmask(int sq);
    U64 set_occupancy(int index, int bits, U64 m);
    U64 pawn_mask(int sq, int side);
    U64 knight_mask(int sq);
    U64 king_mask(int sq);
    U64 pawn_non_attack(int sq, int side);

 public:
    Bitboard();
    virtual ~Bitboard();
    void _init();

    U64 get_all_w_bitboard();
    U64 get_all_b_bitboard();
    U64 get_all_pieces_bitboard() const;
    U64 get_piece_bitboard(int piece) const;
    U64 get_Pieces_BB(int piece_type);
    U64 bishop_attacks(U64 occ, SquareIndices);
    U64 rook_attacks(U64 occ, SquareIndices);
    U64 queen_attacks(U64 occ, SquareIndices);
    U64 get_piece_attacks(int type, SquareIndices);
    U64 get_non_attack_moves(int type, SquareIndices);
    void generate_all_moves(bool side, MoveList*);
    void clear_bit_at_player_pieces(bool is_black, int pos);
    void move(int type, int f, int t);
    void capture_piece(int captured, int pos);
    void put_piece_back(int captured, int pos);
    void update_killers(Move mv);
    void update_search_history(int piece, int to, int depth);
    void make_move_bb(int piece, int from, int to);
    void undo_move(int piece, int piece_captured, int from, int to);
    int evaluate_board();
    int get_piece_at_pos(int pos);
    Piece* get_piece(int type);
};

#endif /* BITBOARD_H */
