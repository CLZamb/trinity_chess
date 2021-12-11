#ifndef BOARDBITBOARD_H
#define BOARDBITBOARD_H
#include "defs.h"
#include "bit_utilities.h"

class BoardBitboard{
public:
  BoardBitboard() {}
  virtual ~BoardBitboard() {}
  void move(bool is_black, SquareIndices from, SquareIndices to) {
    clear_bit_at_player_pieces(is_black, from);
    set_bit_at_player_pieces(is_black, to);
  }

  U64 get_all_side_pieces(bool is_black) const {
    return (is_black)? m_all_b_pieces : m_all_w_pieces;
  }

  U64 get_all_board_pieces() const {
    return m_occupied;
  }

  void set_bit_at_player_pieces(bool is_black, SquareIndices pos) {
    bitUtility::set_bit(is_black ? &m_all_b_pieces : &m_all_w_pieces, pos);
    bitUtility::set_bit(&m_occupied, pos);
  }

private:
  void clear_bit_at_player_pieces(bool is_black, SquareIndices pos) {
    bitUtility::clear_bit(is_black ? &m_all_b_pieces : &m_all_w_pieces, pos);
    bitUtility::clear_bit(&m_occupied, pos);
  }

  U64 m_all_w_pieces = BLANK;
  U64 m_all_b_pieces = BLANK;
  U64 m_occupied = BLANK;
};

#endif /* BOARDBITBOARD_H */
