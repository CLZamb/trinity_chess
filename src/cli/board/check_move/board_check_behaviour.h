#ifndef BOARD_CHECK_BEHAVIOUR_H
#define BOARD_CHECK_BEHAVIOUR_H

#include "IBoard_check_behaviour.h"
#include "board/board_representation/board.h"
#include "board/check_move/pieces/pieces_legal_moves.h"
#include "game/players/player_info.hpp"
#include "utils/string_utils.h"

class CheckBehaviour : public IBoardCheckBehaviour {
public:
  CheckBehaviour(Board &board, PlayerInfo &turn);

  bool is_legal_move(Move &m) override;
  bool is_string_format_valid(const string &s) override;
  bool is_in_check(const Move &m) override;
  bool is_checkmate() override;

private:
  bool check_checkmate();
  U64 get_all_king_possible_positions();
  bool piece_belongs_to_player(const Piecetype &pc);
  bool are_same_color(const Piecetype &p, const Piecetype &c);
  bool can_check(const Move &m);
  bool can_be_block_by_another_piece(const Move &m);
  bool is_king_piece_attacked();
  Color get_opponent_player_color();
  bool can_opponent_attack_square(const unsigned int &to);

  PiecesLegalMoves m_pieces;
  Board &m_board;
  PlayerInfo &m_turn_info;
  BoardBitboard &m_board_bitboard;
};

#endif /* BOARD_CHECK_H */
