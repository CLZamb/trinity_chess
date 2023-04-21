#ifndef BOARD_CHECK_INFO_DECORATOR_H
#define BOARD_CHECK_INFO_DECORATOR_H

#include <memory>
#include "board/check_move/board_check.h"

using std::unique_ptr;

class BoardCheckDecorator : public IBoardCheckBehaviour {
 public:
  explicit BoardCheckDecorator(std::unique_ptr<IBoardCheckBehaviour>&& b): 
    _m_board_check_info_behaviour(std::move(b)) {}

  virtual bool is_string_format_valid(const std::string& s) {
    return _m_board_check_info_behaviour->is_string_format_valid(s);
  }

  virtual bool is_in_check(const Move& mv) {
    return _m_board_check_info_behaviour->is_in_check(mv);
  }

  virtual bool is_legal_move(Move& m) {
    return _m_board_check_info_behaviour->is_legal_move(m);
  }

  virtual bool is_checkmate() {
    return _m_board_check_info_behaviour->is_checkmate();
  }

private:
  std::unique_ptr<IBoardCheckBehaviour> _m_board_check_info_behaviour;
};

#endif /* BOARD_CHECK_H */
