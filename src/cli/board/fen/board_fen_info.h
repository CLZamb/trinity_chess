#ifndef BOARD_FEN_INFO_H
#define BOARD_FEN_INFO_H

#include "board/board_representation/board.h"
#include "game/turn/game_turn_observer.h"

class BoardFenInfo : public GameTurnObserver {
 public:
  BoardFenInfo(Board& b);
  virtual ~BoardFenInfo() = default;
  void update_turn(const PlayerInfo &) override;
  Piecetype get_piece_at_square(const size_t &pos);
  void clear();
  void set_piece_at_square(const SquareIndices &i, const Piecetype& p);
  void set_castle_permission(CastlePermission perm);
  void set_en_passant_square(SquareIndices sq);

  char get_side_turn();
  string get_castling_rights_string();
  string get_en_passant_square_string();
  string get_half_moves();
  string get_full_moves();

 protected:
  const int &get_castle_permission();
  const SquareIndices &get_en_passant_square();

 private:
  char side_turn;
  Board& m_board;
};

#endif /* BOARD_FEN_INFO_H */
