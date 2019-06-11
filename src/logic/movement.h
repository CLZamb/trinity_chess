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

 private:
    bool check_move(Piece*, int from, int to);
    Piecetype take_piece(int pos);
    Piecetype capture_piece(int pos);
    vector<unsigned int> prev_moves;

    friend class Search;
    Board* p_board;
    ZobristKey m_zkey;
    TTable m_hash_table;
    bool checkmate = false;
};

#endif /* MOVEMENT_H */
