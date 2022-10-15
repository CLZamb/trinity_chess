#ifndef CASTLING_H
#define CASTLING_H

#include "board/headers/defs.h"
#include "game/headers/move.hpp"
#include <unordered_map>

using std::unordered_map;

class Castling {
public:
  Castling ();
  const Move &get_rook_castle_move(const CastlePermission &cp) const;
  bool is_castle_move(const Move& m, const Color &side);
  void assign_castle_rights_to_move(Move& m, const Color &side);
  CastleSquares get_castle_rook_initial_position(const Move& m, const Color &side);
  const int &get_castle_permission();

private:
  static const Move m_wkca{Move_Utils::make_move(ROOK_WHITE_CA_KING_SIDE_FROM_POS, ROOK_WHITE_CA_KING_SIDE_TO_POS, wR)};
  static const Move m_wqca{Move_Utils::make_move(ROOK_WHITE_CA_QUEEN_SIDE_FROM_POS, ROOK_WHITE_CA_QUEEN_SIDE_TO_POS, wR)};
  static const Move m_bkca{Move_Utils::make_move(ROOK_BLACK_CA_KING_SIDE_FROM_POS, ROOK_BLACK_CA_KING_SIDE_TO_POS, wR)};
  static const Move m_bqca{Move_Utils::make_move(ROOK_BLACK_CA_QUEEN_SIDE_FROM_POS, ROOK_BLACK_CA_QUEEN_SIDE_TO_POS, wR)};

  static const unordered_map<CastlePermission, const Move> m_rook_castle_pos;
  static const unordered_map<CastleSquares, CastlePermission> m_white_permission;
  static const unordered_map<CastleSquares, CastlePermission> m_black_permission;
  static const unordered_map<Color, const unordered_map<CastleSquares, CastlePermission>> m_castle_permission;
  int castle_perm{NO_CASTLING};
  // static const unordered_map<CastlePermission, std::pair<CastleSquares, CastleSquares>> m_rook_castle_rights_assigment;
};

#endif /* CASTLING_H */
