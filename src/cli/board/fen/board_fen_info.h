#ifndef BOARD_FEN_INFO_H
#define BOARD_FEN_INFO_H

#include "move.hpp"
#include "special_moves/special_move_controller.h"
#include "string_utils.h"
#include "utilities.h"

class BoardFenInfo {
 public:
  BoardFenInfo() = default;
  virtual ~BoardFenInfo() = default;
  virtual Piecetype get_piece_at_square(const size_t &pos) = 0;
  virtual void clear() = 0;
  virtual void set_piece_at_square(const SquareIndices &i, const Piecetype& p) = 0;
  virtual void set_castle_permission(CastlePermission perm) = 0;
  virtual void set_en_passant_square(SquareIndices sq) = 0;

  char get_side_turn();
  string get_castling_rights_string();
  string get_en_passant_square_string();
  string get_half_moves();
  string get_full_moves();

 protected:
  virtual const int &get_castle_permission() = 0;
  virtual const SquareIndices &get_en_passant_square() = 0;
  void update_fen_current_side_turn_color(Color c);
  void update_str_half_moves(const int& hm);
  void update_str_full_moves(const int& fm);
  bool is_king_piece(const Piecetype& pct);

 private:
  string str_half_moves;
  string str_full_moves;
  Color current_side_color;
  char side_turn;
};

#endif /* BOARD_FEN_INFO_H */
