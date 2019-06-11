#include "transposition_table.h"

void TTable::set(ZobristKey key, TTEntry entry) {
  auto result = m_table.insert(std::make_pair(key.get_zobrist_key(), entry));

  if (!result.second) {
    result.first->second = entry;
  }
}

const TTEntry* TTable::get_entry(const ZobristKey &key) const {
  auto got = m_table.find(key.get_zobrist_key());

  if (got != m_table.end())
    return &m_table.at(key.get_zobrist_key());

  return nullptr;
}

void TTable::clear() { m_table.clear(); }
