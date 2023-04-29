#ifndef BOARD_CHECK_BEHAVIOUR_H
#define BOARD_CHECK_BEHAVIOUR_H

#include "IBoard_check_behaviour.h"
#include "board/check_move/pieces/king.hpp"
#include "board/check_move/pieces/knight.hpp"
#include "board/check_move/pieces/pawn.hpp"
#include "board/check_move/pieces/pieces_legal_moves.h"
#include "utils/string_utils.h"

class CheckBehaviour : public IBoardCheckBehaviour {
public:
  CheckBehaviour(Position &board, Color &side);

  bool is_legal_move(Move &m) override;
  bool is_string_format_valid(const string &s) override;
  bool is_in_check(const Move &m) override;
  bool is_checkmate() override;

private:
  bool check_checkmate();
  Bitboard get_all_king_possible_positions();
  bool piece_belongs_to_player(const Piece &pc);
  bool are_same_color(const Piece &p, const Piece &c);
  bool can_check(const Move &m);
  bool can_be_block_by_another_piece(const Move &m);
  bool is_king_piece_attacked();
  Color get_opponent_player_color();
  bool can_opponent_attack_square(const Square &to);

  PiecesLegalMoves m_pieces;
  Color &m_side;
  Position &m_position;

  MagicBitboard m_magic_bitboard;
  BishopMagicBitboard m_bishop_attacks;
  QueenMagicBitboard m_queen_attacks;
  RookMagicBitboard m_rook_attacks;
  Pawn<BLACK> m_black_pawn;
  King<BLACK> m_black_king;
  Knight<BLACK> m_black_knight;
};

#endif /* BOARD_CHECK_H */
