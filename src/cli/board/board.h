#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "string_utils.h"
#include "game_turn_observer.h"
#include "fen/board_fen_info.h"

class Board : public BoardFenInfo, public GameTurnObserver {
public:
  Board();
  // GameTurnObserver
  void update_turn(const PlayerInfo &) override;
  // BoardFenInfo
  Piecetype get_piece_at_square(const size_t &pos) override;
  void clear() override;
  void set_piece_at_square(const SquareIndices &s, const Piecetype &p) override;
  void set_castle_permission(CastlePermission perm) override;
  void set_en_passant_square(SquareIndices sq) override;
  // board_check
  BoardBitboard &get_board_bitboard();
  SquareIndices get_king_position(Color c);
  //
  void make_move(Move mv);
  Move string_to_move(const string &);

private:
  // boardFenInfo
  const int &get_castle_permission() override;
  const SquareIndices &get_en_passant_square() override;
  void update_king_position(const Move &mv);
  void set_king_position(Color c, const SquareIndices &pos);
  void move_piece_to_square(const Move &);
  void update_half_moves(const Move& m);
  void update_full_moves();

  Squares m_squares;
  BoardBitboard m_board_bitboard;
  PlayerInfo m_turn_info;
  int half_moves{0};
  int full_moves{1};
  SquareIndices m_black_king_position;
  SquareIndices m_white_king_position;
  SpecialMoveController m_special_move;
};

#endif /* BOARD_H */
