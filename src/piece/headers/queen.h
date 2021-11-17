#ifndef QUEEN_H
#define QUEEN_H 

#include "piece.h"
#include "magic_bitboard.h"

template<Color color>
class Queen : public Piece {
public:
  explicit Queen(const MagicBitboard& m_bb);
  virtual ~Queen();
  bool is_legal_non_attack_move(const Move&, const BoardBitboard& board) override;
  bool is_legal_attack_move(const Move&, const BoardBitboard& board) override;

private:
  const MagicBitboard * const m_bb;
};

#endif /* ifndef QUEEN_H */
