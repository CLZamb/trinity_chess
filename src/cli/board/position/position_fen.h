#ifndef POSITION_FEN_H
#define POSITION_FEN_H

#include <string>

#include "board/position/position.h"
#include "components/fen_fields.hpp"

class PositionFen {
 public:
  PositionFen() = default;
  explicit PositionFen(const FenFields &fen, Position &position);
  void parse_fen(const FenFields &fen, Position &position);
  std::string get_fen(Position &position);

 private:
  void add_empty_space(std::string &fen, int &space);
  Square make_sq(int& rank, int file);
};

#endif /* POSITION_FEN_H */
