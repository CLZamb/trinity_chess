#ifndef TRANSPOSITION_TABLE_H
#define TRANSPOSITION_TABLE_H
#include "ZobristKey.h"
#include "Transposition_table_entry.h"
#include <unordered_map>

class TTable
{
private:
  std::unordered_map<U64, TTEntry> m_table;

public:
  enum Flag {
    EXACT,
    LOWER_BOUND,
    UPPER_BOUND
  };

  TTable() = default;
  void set(ZobristKey, TTEntry);
  const TTEntry *get_entry(const ZobristKey &) const;
  void clear();
};

#endif /* TRANSPOSITION_TABLE_H */
