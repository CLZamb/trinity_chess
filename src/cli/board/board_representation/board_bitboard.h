#ifndef BOARD_BITBOARD_H
#define BOARD_BITBOARD_H

#include <array>
#include <vector>
#include "utils/move.hpp"

class BoardBitboard {
public:
  BoardBitboard() {}
  virtual ~BoardBitboard() {}
  void move(const Move& m) {
    Color color = utils::check::get_color_piece(Move_Utils::get_piece(m));
    do_move(color, Move_Utils::get_from(m), Move_Utils::get_to(m));
  }

  void undo_move(const Move& m) {
    Color color = utils::check::get_color_piece(Move_Utils::get_piece(m));
    do_move(color, Move_Utils::get_to(m), Move_Utils::get_from(m));
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
    for (unsigned int pos = Squarebegin; pos < SquareEnd; pos++) {
      clear_bit_at_player_pieces(BLACK, SquareIndices(pos));
      clear_bit_at_player_pieces(WHITE, SquareIndices(pos));
    }
  }

  std::vector<size_t> get_all_locations_at_side(const Color c) {
    std::vector<size_t> all_locations{static_cast<unsigned long>(bitUtility::count_1s(m_occupancies[c]))};
    U64 temp_locations = m_occupancies[c];
    while(temp_locations) {
      all_locations.push_back(static_cast<unsigned long>(bitUtility::pop_1st_bit(&temp_locations)));
    }
    return all_locations;
  }

private:
  std::array<U64, Color::SIZE + 1> m_occupancies{BLANK};
};

#endif /* BOARD_BITBOARD_H */
