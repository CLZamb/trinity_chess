#ifndef CHESS_VALIDATOR_H
#define CHESS_VALIDATOR_H

#include "IChess_validator.h"
#include "board/check_move/pieces/pieces_legal_moves.h"

class ChessValidator : public IChessValidator {
 public:
  explicit ChessValidator(Position &board);

  void update_turn(const Color &turn) override;
  bool is_string_move_format_valid(const std::string &s) override;
  bool is_player_in_check(const Move &m) override;
  bool is_legal_move(Move &) override;
  bool is_checkmate() override;

 private:
  bool are_same_color(const Piece &piece, const Piece &captured);
  bool piece_belongs_to_player(const Piece &pc);
  Position &m_position;
  Color m_side;
  PiecesLegalMoves m_pieces_legal_moves;
};

#endif /* CHESS_VALIDATOR_H */
