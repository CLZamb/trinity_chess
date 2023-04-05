#ifndef PAWN_PROMITION_H
#define PAWN_PROMITION_H

#include "special_move.h"

class PawnPromition : public SpecialMove {
public:
  PawnPromition ();
  virtual ~PawnPromition ();
  bool is_pawn_promotion(const Move&);
  void assign_special_to_move(Move& m) override;
  void handle_special_move(const Move& m, Squares &s) override;

private:
  bool is_pawn_piece(const Piecetype pct);
};

#endif /* PAWN_PROMITION_H */
