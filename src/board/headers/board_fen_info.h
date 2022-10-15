#ifndef BOARD_FEN_INFO_H
#define BOARD_FEN_INFO_H

#include "board/headers/defs.h"
#include "board/headers/utils.h"
class BoardFenInfo {
private:
public:
  virtual Piecetype get_piece_at_square(const int &pos) = 0;
  virtual void clear() = 0;
  virtual void set_piece_at_square(const SquareIndices &i, const Piecetype& p) = 0;
  virtual void set_castle_permission(CastlePermission perm) = 0;
  virtual void set_en_passant_square(SquareIndices sq) = 0;
};

#endif /* BOARD_FEN_INFO_H */
