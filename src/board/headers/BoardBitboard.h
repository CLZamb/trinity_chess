#ifndef BOARDBITBOARD_H
#define BOARDBITBOARD_H
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
  }

private:
  std::array<U64, Color::SIZE + 1> m_occupancies{BLANK};
};

#endif /* BOARDBITBOARD_H */
