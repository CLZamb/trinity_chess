#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "magic_bitboard.h"

template<Color color>
class Rook : public Piece {
public:
  explicit Rook(const MagicBitboard& m_bb);
  virtual ~Rook();
  bool is_legal_non_attack_move(const Move&, const BoardBitboard& board) override;
  bool is_legal_attack_move(const Move&, const BoardBitboard& board) override;

private:
  const MagicBitboard * const m_bb;
};


#endif /* ROOK_H */
