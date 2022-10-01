#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "board/headers/board_fen.h"
#include "board/headers/castling.h"
#include "board/headers/defs.h"
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

class Board : public GameTurnObserver {
public:
  explicit Board(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  void update_turn(const PlayerInfo &) override;
  void make_move(Move mv);
  bool is_checkmate();
  bool is_legal_move(Move &);
  BoardFen &get_board_fen();
  Move string_to_move(const string &);

private:
  void move_piece_to_square(const Move &);
  bool can_castle();
  bool check_piece_belongs_to_player(const Piecetype);
  bool is_captured_piece_in_same_side(const Piecetype, const Piecetype);
  bool is_castle_move(const Move& m);
  SquareIndices get_en_passant_move(const Move& m);
  void assign_castle_rights(Move& m);
  void move_castle_move(const std::pair<CastleSquares, CastleSquares>& rook_pos);
  bool is_pawn_piece(const Piecetype);
  bool is_first_move(const Move& m);
  bool is_double_forward_move(const Move& m);
  void save_en_passant_move(const SquareIndices& sq);
  bool is_en_passand_move(const Move& m);

  Squares m_squares;
  Pieces m_pieces;
  BoardBitboard m_board_bitboard;
  bool checkmate{false};
  PlayerInfo m_turn_info;
  BoardFen m_fen;
  Castling m_castling;
};

#endif /* BOARD_H */
