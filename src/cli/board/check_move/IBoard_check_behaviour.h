#ifndef IBOARD_CHECK_BEHAVIOUR_H
#define IBOARD_CHECK_BEHAVIOUR_H

#include "utils/move.hpp"

class IBoardCheckBehaviour {
public:
  virtual ~IBoardCheckBehaviour() {}
  virtual bool is_in_check(const Move&m) = 0;
  virtual bool is_string_format_valid(const std::string& s) = 0;
  virtual bool is_legal_move(Move &) = 0;
  virtual bool is_checkmate() = 0;
};

#endif /* BOARD_CHECK_H */
