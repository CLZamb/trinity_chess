#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "utils/defs.h"

template <Color color>
class Knight : public PieceBase {
 public:
  Knight() : PieceBase(color == BLACK ? bN : wN) { _init_moves(); }

  virtual ~Knight() {}

  bool is_legal_move(Move &m, Position &board) override {
    Square from = MoveUtils::get_from(m);
    Bitboard to = ONE << MoveUtils::get_to(m);
    Piece captured = MoveUtils::get_captured_piece(m);
    Bitboard free_squares = ~board.get_occupied_squares_as_bitboard();

    if (captured) {
      free_squares |= board.get_king_position(utils::check::get_color_piece(captured));
    }

    return m_attacks[from] & to & free_squares;
  }

  Bitboard get_attacks(Bitboard bb, Square sq) override {
    return m_attacks[sq] & bb & sq;
  }

 private:
  Bitboard knight_mask(int sq) {
    Bitboard result = BLANK;
    Bitboard from_sq = ONE << sq;
    Bitboard shift = BLANK;

    shift = bitUtility::shift<bitUtility::SOUTH_SOUTH>(from_sq);
    shift = bitUtility::shift<bitUtility::WEST>(shift);
    if (shift & NOT_H_FILE) {
      result |= shift & NOT_H_FILE;
    }

    shift = bitUtility::shift<bitUtility::SOUTH_SOUTH>(from_sq);
    shift = bitUtility::shift<bitUtility::EAST>(shift);
    if (shift & NOT_A_FILE) {
      result |= shift & NOT_A_FILE;
    }

    shift = bitUtility::shift<bitUtility::SOUTH_WEST>(from_sq);
    shift = bitUtility::shift<bitUtility::WEST>(shift);
    if (shift & NOT_GH_FILE) {
      result |= shift & NOT_GH_FILE;
    }

    shift = bitUtility::shift<bitUtility::SOUTH_EAST>(from_sq);
    shift = bitUtility::shift<bitUtility::EAST>(shift);
    if (shift & NOT_AB_FILE) {
      result |= shift & NOT_AB_FILE;
    }

    shift = bitUtility::shift<bitUtility::NORTH_NORTH>(from_sq);
    shift = bitUtility::shift<bitUtility::EAST>(shift);
    if (shift & NOT_A_FILE) {
      result |= shift & NOT_A_FILE;
    }

    shift = bitUtility::shift<bitUtility::NORTH_NORTH>(from_sq);
    shift = bitUtility::shift<bitUtility::WEST>(shift);
    if (shift & NOT_H_FILE) {
      result |= shift & NOT_H_FILE;
    }

    shift = bitUtility::shift<bitUtility::NORTH_EAST>(from_sq);
    shift = bitUtility::shift<bitUtility::EAST>(shift);
    if (shift & NOT_AB_FILE) {
      result |= shift & NOT_AB_FILE;
    }

    shift = bitUtility::shift<bitUtility::NORTH_WEST>(from_sq);
    shift = bitUtility::shift<bitUtility::WEST>(shift);
    if (shift & NOT_GH_FILE) {
      result |= shift & NOT_GH_FILE;
    }

    return result;
  }

  void _init_moves() {
    for (int sq = 0; sq < utils::constant::ksquares; sq++) {
      m_attacks[sq] = knight_mask(sq);
    }
  }
};

#endif /* KNIGHT_H */
