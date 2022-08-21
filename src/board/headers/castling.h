#ifndef CASTLING_H
#define CASTLING_H

#include "board/headers/defs.h"
#include "game/headers/move.hpp"
#include <unordered_map>

using std::unordered_map;

class Castling {
public:
  Castling ();
  const std::pair<CastleSquares, CastleSquares> &get_rook_castle_move(const CastlePermission &cp) const;
  bool is_castle_move(const Move& m, const Color &side);
  void assign_castle_rights_to_move(Move& m, const Color &side);
  CastleSquares get_castle_rook_initial_position(const Move& m, const Color &side);

private:
  static const unordered_map<CastlePermission, std::pair<CastleSquares, CastleSquares>> m_rook_castle_pos;
  static const unordered_map<CastleSquares, CastlePermission> m_white_permission;
  static const unordered_map<CastleSquares, CastlePermission> m_black_permission;
  static const unordered_map<Color, const unordered_map<CastleSquares, CastlePermission>> m_castle_permission;

  // static const unordered_map<CastlePermission, std::pair<CastleSquares, CastleSquares>> m_rook_castle_rights_assigment;
};

#endif /* CASTLING_H */
