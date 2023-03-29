#ifndef BOARD_FEN_INFO_H
#define BOARD_FEN_INFO_H

#include "utils/utils.h"

class BoardFenInfo {
private:
public:
  virtual Piecetype get_piece_at_square(const size_t &pos) = 0;
  virtual char get_side_turn() = 0;
  virtual string get_en_passant_square_string() = 0;
  virtual string get_castling_rights_string() = 0;
  virtual string get_half_moves() = 0;
  virtual string get_full_moves() = 0;
  virtual void clear() = 0;
  virtual void set_piece_at_square(const SquareIndices &i, const Piecetype& p) = 0;
  virtual void set_castle_permission(CastlePermission perm) = 0;
  virtual void set_en_passant_square(SquareIndices sq) = 0;
  virtual void update_king_position(Color c, const SquareIndices &pos) = 0;
};

#endif /* BOARD_FEN_INFO_H */
