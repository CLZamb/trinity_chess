#ifndef BITBOARD_H
#define BITBOARD_H

#pragma once

#include <vector>
#include <string>
#include "../../headers/move.h"
#include "../../piece/headers/piece.h"
#include "utils.h"
#include "../../piece/headers/magic_bitboard.h"
#include "bit_utilities.h"

typedef std::vector<Move> MoveList;
using bitUtility::Direction;

class Bitboard {
 public:
    Bitboard();
    virtual ~Bitboard();
    void _init();

    U64 get_all_w_bitboard();
    U64 get_all_b_bitboard();
    U64 get_all_pieces_bitboard() const;
    U64 get_piece_bitboard(int piece) const;
    U64 get_Pieces_BB(int piece_type);
    U64 get_piece_attacks(int type, SquareIndices);
    U64 get_non_attack_moves(int type, SquareIndices);
    U64 get_own_pieces_occ(bool side);
    void generate_all_moves(bool side, MoveList*);
    void generate_all_cap_moves(bool side, MoveList*);
    void generate_all_black_moves(MoveList*);
    void clear_bit_at_player_pieces(bool is_black, SquareIndices pos);
    void move(int type, SquareIndices f, SquareIndices t);
    void capture_piece(int captured, SquareIndices pos);
    void put_piece_back(int captured, SquareIndices pos);
    void update_killers(Move mv);
    void update_search_history(int piece, int to, int depth);
    void make_move_bb(int piece, SquareIndices from, SquareIndices to);
    void undo_move(int piece, int piece_captured, SquareIndices from, SquareIndices to);
    void set_bit_at_player_pieces(bool is_black, SquareIndices pos);
    void reset_all_pieces_bitboard();
    void set_piece_at_pos(int piece, SquareIndices pos);
    void clear_search_history();
    void clear_killer_moves();
    void reset_ply();
    void increment_ply();
    void deincrement_ply();
    int evaluate_board();
    int get_movility_score(int piece);
    int get_ply();
    Piecetype get_piece_at_pos(int pos);
    Piece* get_piece(int type);


 private:
    const U64 PAWNSTART =
      0b0000000011111111000000000000000000000000000000001111111100000000;
    const U64 ROOKSTART =
      0b1000000100000000000000000000000000000000000000000000000010000001;
    const U64 KNIGHTSTART =
      0b0100001000000000000000000000000000000000000000000000000001000010;
    const U64 BISHOPSTART =
      0b0010010000000000000000000000000000000000000000000000000000100100;
    const U64 QUEENSTART =
      0b0000100000000000000000000000000000000000000000000000000000001000;
    const U64 KINGSTART =
      0b0001000000000000000000000000000000000000000000000000000000010000;
    const U64 ALLWHITESTART =
      0b0000000000000000000000000000000000000000000000001111111111111111;
    const U64 ALLBLACKSTART =
      0b1111111111111111000000000000000000000000000000000000000000000000;

    //Masking
    const U64 ROWMASK[8] = {
      0b0000000000000000000000000000000000000000000000000000000011111111,
      0b0000000000000000000000000000000000000000000000001111111100000000,
      0b0000000000000000000000000000000000000000111111110000000000000000,
      0b0000000000000000000000000000000011111111000000000000000000000000,
      0b0000000000000000000000001111111100000000000000000000000000000000,
      0b0000000000000000111111110000000000000000000000000000000000000000,
      0b0000000011111111000000000000000000000000000000000000000000000000,
      0b1111111100000000000000000000000000000000000000000000000000000000
    };

    //Clear
    const U64 COLUMNCLEAR[8] = {
      0b1111111011111110111111101111111011111110111111101111111011111110,
      0b1111110111111101111111011111110111111101111111011111110111111101,
      0b1111101111111011111110111111101111111011111110111111101111111011,
      0b1111011111110111111101111111011111110111111101111111011111110111,
      0b1110111111101111111011111110111111101111111011111110111111101111,
      0b1101111111011111110111111101111111011111110111111101111111011111,
      0b1011111110111111101111111011111110111111101111111011111110111111,
      0b0111111101111111011111110111111101111111011111110111111101111111,
    };


    const U64 BLANK =  0b0000000000000000000000000000000000000000000000000000000000000000;
    const U64 FULL =   0b1111111111111111111111111111111111111111111111111111111111111111;

    const U64 NOT_H_FILE = 0b0111111101111111011111110111111101111111011111110111111101111111;
    const U64 NOT_GH_FILE = 0b0011111100111111001111110011111100111111001111110011111100111111;
    const U64 NOT_A_FILE = 0b1111111011111110111111101111111011111110111111101111111011111110;
    const U64 NOT_AB_FILE = 0b1111110011111100111111001111110011111100111111001111110011111100;


    enum Pieces : int {
      PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING,
    };

    enum PieceColor : int {
      WHITE, BLACK
    };

    enum Playertype : int {
      HUMAN, CPU
    };

    enum OPTION : int {
      BEGIN_OPTIONS = 0,
      PLAYER_VS_PLAYER,
      PLAYER_VS_CPU,
      CPU_VS_CPU,
      GAME_OVER,
      CREDITS,
      END_OPTIONS,
    };

    const int VictimScore[13] =
    { 0, 10, 40, 20, 30, 50, 60, 10, 40, 20, 30, 50, 60};
    /**
     * @brief An empty bitboard. (ie. the number 0)
     */
    const int MAX_MOVES = 256;
    const int MAX_DEPTH = 64;


    const int KnightTable[64] = {
      -10, -2, -3, -3, -3, -3, -2, -10,
      -4, -2, 0, 0, 0, 0, -2, -2,
      -3, 0, 5, 3, 3, 5, 0, -3,
      -3, 1, 2, 6, 6, 2, 1, -3,
      -3, 0, 2, 6, 6, 2, 0, -3,
      -3, 1, 5, 6, 6, 5, 1, -3,
      -4, -2, 0, 1, 1, 0, -2, -2,
      -10, -4, -3, -3, -3, -3, -4, -10,
    };

    const int PawnTable[64] = {
      0, 0, 0, 0, 0, 0, 0, 0,
      2, 2, 0, -2, -2, 0, 2, 2,
      1, 0, 0, 1, 1, 0, 0, 1,
      0, 0, 2, 5, 5, 2, 0, 0,
      1, 1, 1, 2, 2, 1, 1, 1,
      2, 2, 2, 4, 4, 2, 2, 2,
      4, 4, 4, 6, 6, 4, 4, 4,
      9, 9, 9, 9, 9, 9, 9, 9
    };

    const int BishopTable[64] = {
      -4, -2, -2, -2, -2, -2, -2, -4,
      -2, 0, 0, 0, 0, 0, 0, -2,
      -2, 0, 1, 2, 2, 1, 0, -2,
      -2, 1, 1, 2, 2, 1, 1, -2,
      -2, 0, 2, 2, 2, 2, 0, -2,
      -2, 2, 2, 2, 2, 2, 2, -2,
      -2, 1, 0, 0, 0, 0, 1, -2,
      -4, -2, -2, -2, -2, -2, -2, -4,
    };

    const int RookTable[64] = {
      0, 0, 0, 0, 0, 0, 0, 0,
      1, 2, 2, 2, 2, 2, 2, 1,
      -1, 0, 1, 1, 1, 1, 0, -1,
      -1, 0, 1, 2, 2, 1, 0, -1,
      -1, 0, 1, 2, 2, 1, 0, -1,
      -1, 0, 1, 1, 1, 1, 0, -1,
      -1, 0, 3, 3, 3, 3, 0, -1,
      0, 0, 0, 1, 1, 0, 0, 0
    };

    const int QueenTable[64] = {
      //queen
      -4, -2, -2, -1, -1, -2, -2, -4,
      -2, 0, 0, 0, 0, 0, 0, -2,
      -2, 0, 1, 1, 1, 1, 0, -2,
      -1, 0, 1, 1, 1, 1, 0, -1,
      0, 0, 1, 1, 1, 1, 0, -1,
      -2, 1, 1, 1, 1, 1, 0, -2,
      -2, 0, 1, 0, 0, 0, 0, -2,
      -4, -2, -2, -1, -1, -2, -2, -4
    };

    const int MIRROR64[64] = {
      56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 ,
      48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
      40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 ,
      32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 ,
      24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 ,
      16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 ,
      8 , 9, 10 , 11 , 12 , 13 , 14 , 15 ,
      0 , 1, 2  , 3 ,  4 , 5 , 6  , 7
    };

    int pop_1st_bit(U64* bb);
    int count_1s(U64 b);
    void _init_bitmasks();
    void _init_nonsliders_attacks();
    void _init_pieces_table_values();
    void _init_slider_masks_shifs_occupancies(int);
    void _init_tables(int);
    void _init_MvvLva();
    void gen_all_piece_moves(int type, MoveList* moveList, bool quiet = true);
    void gen_all_captured_moves(U64 dest, Move mv, MoveList* moveList);
    void gen_all_quiet_moves(U64 dest, Move mv, MoveList* moveList);
    // void gen_pawn_black_moves(int type, MoveList*, bool quite = true);
    // void get_pawn_white_moves(int type, MoveList*, bool quite = true);
    void gen_pawn_black_moves(MoveList* move_list, bool quite);
    void gen_pawn_black_quiet_moves(MoveList*);
    void gen_pawn_black_capture_moves(MoveList*);
    void generate_all_white_moves(MoveList*);
    void gen_pawn_white_quiet_moves(MoveList*);
    void gen_pawn_white_capture_moves(MoveList*);
    void add_quiet_move(Move quiet_move, MoveList* move_list);
    void add_captured_move(Move capture_move, MoveList* move_list);
    void add_en_pessant_move(Move ep_move, MoveList* move_list);
    U64 get_black_pawn_attacks(SquareIndices from);
    U64 get_white_pawn_attacks(SquareIndices from);
    U64 set_occupancy(int index, int bits, U64 m);
    U64 pawn_mask(int sq, int side);
    U64 knight_mask(int sq);
    U64 king_mask(int sq);
    U64 test = PAWNSTART & ALLWHITESTART;
    map<int, U64> m_pieces = {
        {EMPTY, BLANK},  // EMPTY 0
        // black pieces
        {bP, PAWNSTART & ALLBLACKSTART},
        {bR, ROOKSTART & ALLBLACKSTART},
        {bN, KNIGHTSTART & ALLBLACKSTART},
        {bB, BISHOPSTART & ALLBLACKSTART},
        {bQ, QUEENSTART & ALLBLACKSTART},
        {bK, KINGSTART & ALLBLACKSTART},
        // white pieces
        {wP, PAWNSTART & ALLWHITESTART},
        {wR, ROOKSTART & ALLWHITESTART},
        {wN, KNIGHTSTART & ALLWHITESTART},
        {wB, BISHOPSTART & ALLWHITESTART},
        {wQ, QUEENSTART & ALLWHITESTART},
        {wK, KINGSTART & ALLWHITESTART},  // 12
    };

    int ply = 0;
    int pieces_score[13][utils::constant::ktotal_number_squares] = {{0}};
    int MvvLvaScores[13][13];
    int search_history[13][utils::constant::ktotal_number_squares] = {{0}};
    Move killers[2][utils::constant::kMaxDepth];
    MagicBitboard magic_bb;

    U64 m_all_w_pieces = ALLWHITESTART;
    U64 m_all_b_pieces = ALLBLACKSTART;
    U64 m_occupied = ALLWHITESTART|ALLBLACKSTART;

    U64 m_w_pawn_attacks[utils::constant::ktotal_number_squares];
    U64 m_b_pawn_attacks[utils::constant::ktotal_number_squares];
    U64 m_knight_attacks[utils::constant::ktotal_number_squares];
    U64 m_king_attacks[utils::constant::ktotal_number_squares];

    U64 Enpessant[2];
};

#endif /* BITBOARD_H */
