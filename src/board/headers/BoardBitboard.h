#ifndef BOARDBITBOARD_H
#define BOARDBITBOARD_H
#include "board/headers/castling.h"
#include "defs.h"
#include "bit_utilities.h"
#include "game/headers/move.hpp"
#include <cstdlib>
#include <string>
#include <array>

class BoardBitboard {
public:
  BoardBitboard() {}
  virtual ~BoardBitboard() {}
  void move(const Move& m) {
    Color color = utils::check::get_color_piece(Move_Utils::get_piece(m));
    do_move(color, Move_Utils::get_from(m), Move_Utils::get_to(m));

    if (Move_Utils::can_castle(m)) {
      CastlePermission caslte_perm = Move_Utils::get_castle_permission(m);
      move_castle_move(color, m_caslting.get_rook_castle_move(caslte_perm));
    }
  }

  void move_castle_move(const Color c, const std::pair<CastleSquares, CastleSquares>& r_pos) {
    SquareIndices from = static_cast<SquareIndices>(r_pos.first);
    SquareIndices to = static_cast<SquareIndices>(r_pos.second);
    do_move(c, from, to);
  }

  void do_move(const Color c, const SquareIndices from, const SquareIndices to) {
    clear_bit_at_player_pieces(c, from);
    set_bit_at_player_pieces(c, to);
  }

  U64 operator[](Color c) {
    return m_occupancies[c];
  }

  bool is_occupied_at_pos(const SquareIndices pos) {
    return m_occupancies[BOTH] & (ONE << pos);
  }

  void set_bit_at_player_pieces(Color c, SquareIndices pos) {
    bitUtility::set_bit(&m_occupancies[c], pos);
    bitUtility::set_bit(&m_occupancies[BOTH], pos);
  }

  void clear_bit_at_player_pieces(Color c, SquareIndices pos) {
    bitUtility::clear_bit(&m_occupancies[c], pos);
    bitUtility::clear_bit(&m_occupancies[BOTH], pos);
  }

  void clear() {
    for (int pos = Squarebegin; pos < SquareEnd; pos++) {
      clear_bit_at_player_pieces(BLACK, static_cast<SquareIndices>(pos));
      clear_bit_at_player_pieces(WHITE, static_cast<SquareIndices>(pos));
    }
    castle_perm = NO_CASTLING;
  }

  void set_castle_permission(CastlePermission perm) {
    castle_perm |= perm;
  }

  const int &get_castle_permission() {
    return castle_perm;
  }

private:
  std::array<U64, Color::SIZE + 1> m_occupancies{BLANK};
  int castle_perm{NO_CASTLING};
  Castling m_caslting;
};

#endif /* BOARDBITBOARD_H */
