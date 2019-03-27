#include "Transposition_table_entry.h"

Move* TTEntry::get_best_move() const {
  return m_best_move;
}

int TTEntry::get_score() const {
  return m_score;
}

int TTEntry::get_depth() const {
  return m_depth;
}

TTEntry::Flag TTEntry::get_flag() const {
  return m_flag;
}
