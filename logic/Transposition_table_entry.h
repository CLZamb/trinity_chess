#ifndef TRASNPOSITION_TABLE_ENTRY_H
#define TRASNPOSITION_TABLE_ENTRY_H

#include <random>
#include "move.h"

class TTEntry {
 public:
  enum Flag { UPPER_BOUND, EXACT, LOWER_BOUND };

  TTEntry(Move* best, int score, int depth, Flag flag) :
    m_best_move(best), m_score(score),  m_depth(depth), m_flag(flag) {}
  virtual ~TTEntry() {}

  Move* get_best_move() const;
  int get_score() const;
  int get_depth() const;
  Flag get_flag() const;

 private:
  Move* m_best_move;
  int m_score;
  int m_depth;
  Flag m_flag;
};

#endif /* TRASNPOSITION_TABLE_ENTRY_H */
