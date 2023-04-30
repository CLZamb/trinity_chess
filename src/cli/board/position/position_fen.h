#ifndef POSITION_FEN_H
#define POSITION_FEN_H

#include <string>

#include "board/position/position.h"
#include "ui/components/fen_component_parts.hpp"

/*
 <FEN> ::=  <Piece Placement>
        ' ' <Side to move>
        ' ' <Castling ability>
        ' ' <En passant target square>
        ' ' <Halfmove clock>
        ' ' <Fullmove counter>
*/

class PositionFen {
 public:
  PositionFen();
  virtual ~PositionFen() = default;
  void parse_fen(const std::string &fen, Position &position);
  std::string get_fen(Position &position);
  void split_fen_into_its_component_parts(const std::string &fen,
                                          FenComponentParts &fcp);

 private:
  void add_empty_space(std::string &fen, int &space);
};

#endif /* POSITION_FEN_H */
