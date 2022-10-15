#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "board/headers/castling.h"
#include "board/headers/defs.h"
#include "board/headers/special_move.h"
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
  const int &get_castle_permission();
  const SquareIndices &get_en_passant_square();
  // fen
  Piecetype get_piece_at_square(const int &pos) override;
  void clear() override;
  void set_piece_at_square(const SquareIndices &s, const Piecetype &p) override;
  void set_castle_permission(CastlePermission perm) override;
  void set_en_passant_square(SquareIndices sq) override;

private:
  void move_piece_to_square(const Move &);
  bool can_castle();
  bool check_piece_belongs_to_player(const Piecetype);
  bool is_captured_piece_in_same_side(const Piecetype, const Piecetype);
  SquareIndices get_en_passant_move(const Move& m);
  void assign_castle_rights(Move& m);
  void move_rook_castle_move(const Move& rook_pos);
  bool is_pawn_piece(const Piecetype);
  bool is_first_move(const Move& m);
  bool is_double_forward_move(const Move& m);
  bool is_en_passand_move(const Move& m);

  Squares m_squares;
  Pieces m_pieces;
  BoardBitboard m_board_bitboard;
  bool checkmate{false};
  PlayerInfo m_turn_info;

  // int castle_perm{NO_CASTLING};
  SpecialMove m_special_move;
  // Castling m_castling;
  // SquareIndices en_passant_pos{SquareNull};
  // EnPassant m_en_passant;
};

#endif /* BOARD_H */
