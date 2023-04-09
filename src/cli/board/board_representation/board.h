#ifndef BOARD_REPRESENTATION_H
#define BOARD_REPRESENTATION_H

#include <string>
#include "board/special_moves/special_move_controller.h"
#include "board_bitboard.hpp"

using std::string;

class Board {
public:
  Board();
  // GameTurnObsqrver
  // BoardFenInfo
  int get_half_moves();
  int get_full_moves();
  Piecetype get_piece_at_square(const size_t &pos);
  void clear();
  void set_piece_at_square(const SquareIndices &s, const Piecetype &p);
  void set_castle_permission(CastlePermission perm);
  void set_en_passant_square(SquareIndices sq);
  // board_check
  BoardBitboard &get_board_bitboard();
  SquareIndices get_king_position(Color c);
  //
  void make_move(const Move& mv);
  Move string_to_move(const string &);
  const int &get_castle_permission();
  const SquareIndices &get_en_passant_square();

private:
  // boardFenInfo
  void update_king_position(const Move &mv);
  void update_king_position(Color c, const SquareIndices &pos);
  void move_piece_to_square(const Move &);
  void update_half_moves(const Move& m);
  void update_full_moves();

  Squares m_squares;
  BoardBitboard m_board_bitboard;

  int half_moves{0};
  int full_moves{1};
  SquareIndices m_black_king_position;
  SquareIndices m_white_king_position;
  SpecialMoveController m_special_move;
};

#endif /* BOARD_REPRESENTATION_H */
