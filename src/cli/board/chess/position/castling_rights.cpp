#include "castling_rights.h"

#include "board/chess/position/position_utils.h"
#include "utils/string_utils.h"

const std::unordered_map<char, CastlePermission>
    CastlingRights::m_castle_permision{
        {'Q',        WQCA},
        {'K',        WKCA},
        {'q',        BQCA},
        {'k',        BKCA},
        {'-', NO_CASTLING},
};

CastlingRights::CastlingRights() {}

void CastlingRights::set_castle_permission(const char c) {
  if (m_castle_permision.find(c) == m_castle_permision.end()) {
    return;
  }

  m_castle_perm |= m_castle_permision.at(c);
}

void CastlingRights::remove_castle_permission(const CastlePermission &perm) {
  m_castle_perm ^= perm;
}

CastlePermission CastlingRights::get_castle_permission(Move &m) {
  Color side = utils::check::get_color_piece(MoveUtils::get_piece(m));
  CastleSquares to = static_cast<CastleSquares>(MoveUtils::get_to(m));
  return m_castle_permission.at(side).at(to);
}

CastlePermission CastlingRights::get_castle_permission() {
  return static_cast<CastlePermission>(m_castle_perm);
}

std::string CastlingRights::get_castling_rights_as_string() {
  if (m_castle_perm == NO_CASTLING) {
    return "-";
  }

  std::string permissions_str;

  for (CastlePermission c : {WKCA, WQCA, BKCA, BQCA, NO_CASTLING}) {
    if (m_castle_perm & c) {
      permissions_str += castle_permision_char.at(c);
    }
  }

  return permissions_str;
}

void CastlingRights::clear() { m_castle_perm = NO_CASTLING; }
