#ifndef CASTLING_RIGHTS_H
#define CASTLING_RIGHTS_H

#include <unordered_map>

#include "game/game_typedefs.h"
#include "position_typedefs.h"
#include "utils/move.hpp"

class CastlingRights {
 public:
  CastlingRights();
  void set_castle_permission(const char c);
  void remove_castle_permission(const CastlePermission &perm);
  CastlePermission get_castle_permission();
  CastlePermission get_castle_permission(Move &m);
  std::string get_castling_rights_as_string();
  void clear();

 private:
  unsigned int m_castle_perm{NO_CASTLING};

  static const std::unordered_map<char, CastlePermission> m_castle_permision;

  const std::unordered_map<CastlePermission, char> castle_permision_char{
      {WQCA, 'Q'},
      {WKCA, 'K'},
      {BQCA, 'q'},
      {BKCA, 'k'},
  };

  const std::unordered_map<CastleSquares, CastlePermission> m_white_permission{
      { WK_CA_KING_SIDE_END_POS, WKCA},
      {WK_CA_QUEEN_SIDE_END_POS, WQCA},
  };

  const std::unordered_map<CastleSquares, CastlePermission> m_black_permission{
      { BK_CA_KING_SIDE_END_POS, BKCA},
      {BK_CA_QUEEN_SIDE_END_POS, BQCA},
  };

  const std::unordered_map<
      Color,
      const std::unordered_map<CastleSquares, CastlePermission>>
      m_castle_permission{
          {WHITE, m_white_permission},
          {BLACK, m_black_permission},
  };
};

#endif /* CASTLING_RIGHTS_H */
