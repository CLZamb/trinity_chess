#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "board/headers/castling.h"
#include "board/headers/defs.h"
#include "board/headers/special_move_controller.h"
#include "board/headers/squares.h"
#include "board/headers/utils.h"
#include "common/headers/common.h"
#include "game/headers/game_turn_observer.h"
#include "game/headers/move.hpp"
#include "game/headers/string_utils.h"
#include "model/headers/board_info.h"
#include "piece/headers/piece.h"
#include "piece/headers/pieces.h"
#include "view/headers/board_view.h"
#include "board/headers/board_fen_info.h"

class Board : public BoardFenInfo, public GameTurnObserver {
public:
  Board();
  void update_turn(const PlayerInfo &) override;
  void make_move(Move mv);
  bool is_checkmate();
  bool is_legal_move(Move &);
  Move string_to_move(const string &);
  const SquareIndices &get_en_passant_square();
  // fen
  Piecetype get_piece_at_square(const int &pos) override;
  void clear() override;
  void set_piece_at_square(const SquareIndices &s, const Piecetype &p) override;
  void set_castle_permission(CastlePermission perm) override;
  void set_en_passant_square(SquareIndices sq) override;
  char get_side_turn() override;
  string get_en_passant_square_string() override;
  string get_castling_rights_string() override;
  string get_half_moves() override;
  string get_full_moves() override;

private:
  void move_piece_to_square(const Move &);
  bool can_castle();
  bool check_piece_belongs_to_player(const Piecetype);
  bool is_captured_piece_in_same_color(const Piecetype, const Piecetype);
  void assign_castle_rights(Move& m);
  void update_half_moves(const Move& m);
  void update_full_moves();

  Squares m_squares;
  Pieces m_pieces;
  BoardBitboard m_board_bitboard;
  bool checkmate{false};
  PlayerInfo m_turn_info;

  SpecialMoveController m_special_move;
  int half_moves{0};
  int full_moves{1};
};

#endif /* BOARD_H */
