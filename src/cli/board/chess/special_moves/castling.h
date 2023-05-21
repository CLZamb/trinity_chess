#ifndef CASTLING_H
#define CASTLING_H

#include "board/chess/position/position.h"
#include "utils/move.hpp"
#include <unordered_map>

class Castling {
public:
  Castling();
  virtual ~Castling();
  bool is_castle_move(const Move& m, Position &p);
  CastleSquares get_castle_rook_initial_position(const Move& m, const Color &side);
  void move_rook(const Move& m, Position &s);

private:
  const Move &get_rook_castle_move(const CastlePermission &cp) const;
  bool is_rook_is_at_castling_position(const Move& m, const Position &s);

  static const Move m_wkca{MoveUtils::make_move(ROOK_WHITE_CA_KING_SIDE_FROM_POS, ROOK_WHITE_CA_KING_SIDE_TO_POS, wR)};
  static const Move m_wqca{MoveUtils::make_move(ROOK_WHITE_CA_QUEEN_SIDE_FROM_POS, ROOK_WHITE_CA_QUEEN_SIDE_TO_POS, wR)};
  static const Move m_bkca{MoveUtils::make_move(ROOK_BLACK_CA_KING_SIDE_FROM_POS, ROOK_BLACK_CA_KING_SIDE_TO_POS, wR)};
  static const Move m_bqca{MoveUtils::make_move(ROOK_BLACK_CA_QUEEN_SIDE_FROM_POS, ROOK_BLACK_CA_QUEEN_SIDE_TO_POS, wR)};

  static const std::unordered_map<CastlePermission, const Move> m_rook_castle_pos;
};

#endif /* CASTLING_H */
