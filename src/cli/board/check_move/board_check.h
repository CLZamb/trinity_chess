#ifndef BOARD_CHECK_H
#define BOARD_CHECK_H

#include "board/board_representation/board.h"
#include "pieces/pieces_legal_moves.h"
#include "game/turn/game_turn_observer.h"

class BoardCheck : public GameTurnObserver {
public:
  BoardCheck(Board& b);
  virtual ~BoardCheck() = default;
  BoardCheck(const BoardCheck &) = default;
  void update_turn(const PlayerInfo &turn) override;
  bool is_checkmate();
  bool is_legal_move(Move &);
  bool is_in_check(const Move&m);
  bool can_be_block_by_another_piece(const Move& m);
  bool is_valid_move(const string& str_move, Move& mv);
  string get_error_str();

private:
  bool piece_belongs_to_player(const Piecetype&);
  bool are_same_color(const Piecetype&, const Piecetype&);
  bool is_king_piece_attacked();
  bool can_opponent_attack_square(const unsigned int & pos);
  Color get_opponent_player_color();
  void check_checkmate();
  U64 get_all_king_possible_positions();

  Board &m_board;
  BoardBitboard &m_board_bitboard;
  PlayerInfo m_turn_info;
  PiecesLegalMoves m_pieces;
  bool checkmate{false};
  string str_error;

  static const string Kwrong_format;
  static const string Killegal_move;
  static const string Kcheck_move;
};

#endif /* BOARD_CHECK_H */
