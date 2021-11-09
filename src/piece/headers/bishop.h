#ifndef BISHOP_H
#define BISHOP_H 

#include "piece.h"
#include "magic_bitboard.h"

template<Color color>
class Bishop : public Piece {
public:
  explicit Bishop(const MagicBitboard& m_bb);
  virtual ~Bishop();
  bool is_legal_move(const Move&) override;

private:
  const MagicBitboard * const m_bb;
};

#endif /* ifndef BISHOP_H */

