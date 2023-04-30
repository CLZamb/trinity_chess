#ifndef BOARD_BITBOARD_H
#define BOARD_BITBOARD_H

#include <optional>

#include "board/position/position_typedefs.h"
#include "board_representation.h"
#include "castling_rights.h"
#include "game/turn/game_turn_observer.h"
#include "half_move_clock.h"
#include "position_utils.h"
#include "utils/move.hpp"
#include "utils/string_utils.h"

class Position : public GameTurnObserver {
 public:
  explicit Position();
  virtual ~Position();

  void make_move(const Move &move);
  void undo_move(const Move &move);
  void update_turn(const Color &p_info);
  void set_en_passant_square(Square sq);
  std::string get_en_passant_square_as_string();
  const Square &get_en_passant_square();
  void set_side_to_move(Color c);
  Color get_side_to_move() const;
  void clear();
  void set_halfmoves(int halfmoves);
  void set_fullmoves(int halfmoves);
  std::string get_halfmoves_as_string();
  std::string get_fullmoves_as_string();
  char get_side_turn_as_char();
  // Board BoardRepresentation
  Square get_king_position(Color c);
  const Piece &get_piece_at_square(Square sq) const;
  bool is_occupied_at_square(const Square position);
  Bitboard get_occupied_side_as_bitboard(Color c);
  Bitboard get_occupied_squares_as_bitboard();
  void set_piece_at_square(Piece p, Square position);
  void clear_square(Square s);
  // castling rights
  void set_castle_permission(const char c);
  std::string get_castling_rights_as_string();
  CastlePermission get_castle_permission();
  void remove_castle_permission(const CastlePermission &perm);
  CastlePermission get_castle_permission(Move &m);

 private:
  BoardRepresentation m_board_representation;
  CastlingRights m_castling_rights;
  HalfMoveClock m_half_move_clock;
  Square m_en_passant_pos{SquareNull};
  Color m_side_to_move{NONE};
};

#endif /* BOARD_BITBOARD_H */
