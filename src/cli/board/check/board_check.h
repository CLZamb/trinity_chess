#ifndef BOARD_CHECK_H
#define BOARD_CHECK_H

#include "board.h"
#include "pieces/pieces.h"

class BoardCheck : public GameTurnObserver {
public:
  BoardCheck(Board& b);
  virtual ~BoardCheck() = default;
  BoardCheck(const BoardCheck &) = default;
  void update_turn(const PlayerInfo &turn) override;
  // BoardCheck &operator=(BoardCheck &&) = default;
  // BoardCheck &operator=(const BoardCheck &) = default;
  bool is_checkmate();
  bool is_legal_move(Move &);
  bool is_in_check(const Move&m);
  bool can_be_block_by_another_piece(const Move& m);

private:
  bool check_piece_belongs_to_player(const Piecetype&);
  bool is_captured_piece_same_color(const Piecetype&, const Piecetype&);
  bool is_king_piece(const Piecetype&);
  bool is_king_piece_attacked();
  bool can_opponent_attack_square(const unsigned int & pos);
  Color get_opponent_player_color();
  void check_checkmate();
  U64 get_all_king_possible_positions();

  Board &m_board;
  BoardBitboard &m_board_bitboard;
  PlayerInfo m_turn_info;
  Pieces m_pieces;
  bool checkmate{false};
};

#endif /* BOARD_CHECK_H */
