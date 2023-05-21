#ifndef PAWN_PROMITION_H
#define PAWN_PROMITION_H

#include "board/chess/position/position.h"
#include "utils/move.hpp"

class PawnPromition {
public:
  PawnPromition ();
  virtual ~PawnPromition ();
  bool is_pawn_promotion(const Move&);
  void handle_promotion(const Move& m, Position &s);

private:
  bool is_pawn_piece(const Piece pct);
};

#endif /* PAWN_PROMITION_H */
