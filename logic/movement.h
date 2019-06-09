#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <chrono>
#include <climits>
#include <functional>
#include <set>
#include "transposition_table.h"
#include "ZobristKey.h"
#include "player.h"
#include "bitboard.h"

using std::string;
using std::vector;

class Board;

class Movement {
 public:
    Movement(Board*);
    virtual ~Movement();
    void _init(bool black_to_move);
    void move_piece(Move&);
    void move_piece_bits(Move*);
    void undo_last_bitboard_move(Move last_move);
    void undo_last_move();
    void change_turn();
    bool is_valid_move(Move);
    bool get_checkmate();

    class MoveGenerator;

 private:
    Board* p_board;
    ZobristKey m_zkey;
    TTable m_hash_table;
    bool checkmate = false;
    bool check_move(Piece*, int from, int to);
    Piecetype take_piece(int pos);
    Piecetype capture_piece(int pos);
    vector<unsigned int> prev_moves;
};

class Movement::MoveGenerator {
 public:
    explicit MoveGenerator(Movement* movement);
    Move search_best_move();
    int evaluate_board();

 private:
    bool time_out();
    Move pick_next_move(int index, MoveList*);
    void clear_for_seach();
    void generate_moves(MoveList*);
    void generate_all_cap_moves(MoveList*);
    int negamax(int deapth, int alpha, int beta);
    int quiescence_search(int alpha, int beta);
    int is_repeated_move(const int& depth, int* alpha, int* beta);
    Move root_negamax(int cur_depth);
    TTEntry::Flag get_flag(int alpha, int orig_alpha, int beta);

    Movement* movement = nullptr;
    Board* p_board = nullptr;
    bool has_black_pieces = false;
    bool m_stop = false;
    int best_move = 0;
    int best_score = INT_MIN;
    int score = 0;
    int total_nodes = 0;
    std::chrono::time_point<std::chrono::steady_clock> m_start;
    // int m_time_allocated = 4000;
    int m_time_allocated = 1028;
    int m_elapsed = 0;
};
#endif /* MOVEMENT_H */
