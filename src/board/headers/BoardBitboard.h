#ifndef BOARDBITBOARD_H
#define BOARDBITBOARD_H
#include "defs.h"
#include "bit_utilities.h"
#include "game/headers/move.hpp"

class BoardBitboard{
public:
  BoardBitboard() {}
  virtual ~BoardBitboard() {}
  void move(const Move& m) {
    bool is_black = utils::check::is_black_piece(Move_Utils::get_piece(m));
    clear_bit_at_player_pieces(is_black, Move_Utils::get_from(m));
    set_bit_at_player_pieces(is_black, Move_Utils::get_to(m));
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

  void clear_bit_at_player_pieces(bool is_black, SquareIndices pos) {
    bitUtility::clear_bit(is_black ? &m_all_b_pieces : &m_all_w_pieces, pos);
    bitUtility::clear_bit(&m_occupied, pos);
  }

  void clear() {
    for (int pos = Squarebegin; pos < SquareEnd; pos++) {
      clear_bit_at_player_pieces(BLACK, static_cast<SquareIndices>(pos));
      clear_bit_at_player_pieces(WHITE, static_cast<SquareIndices>(pos));
    }
  }

private:

  U64 m_all_w_pieces = BLANK;
  U64 m_all_b_pieces = BLANK;
  U64 m_occupied = BLANK;
};

#endif /* BOARDBITBOARD_H */
