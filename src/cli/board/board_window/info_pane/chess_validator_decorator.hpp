#ifndef CHESS_VALIDATOR_DECORATOR_H
#define CHESS_VALIDATOR_DECORATOR_H

#include <memory>

#include "board/chess/check_move/IChess_validator.h"

class ChessValidatorDecorator : public IChessValidator {
 public:
  explicit ChessValidatorDecorator(std::unique_ptr<IChessValidator> &&b)
      : _m_board_validator(std::move(b)) {}

  virtual void update_turn(const Color& c) override {
    return _m_board_validator->update_turn(c);
  }

  virtual bool is_string_move_format_valid(const std::string &s) override {
    return _m_board_validator->is_string_move_format_valid(s);
  }

  virtual bool is_player_in_check(const Move &mv) override {
    return _m_board_validator->is_player_in_check(mv);
  }

  virtual bool is_legal_move(Move &m) override {
    return _m_board_validator->is_legal_move(m);
  }

  virtual bool is_checkmate() override {
    return _m_board_validator->is_checkmate();
  }

 private:
  std::unique_ptr<IChessValidator> _m_board_validator;
};

#endif /* CHESS_VALIDATOR_DECORATOR_H */
