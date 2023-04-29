#ifndef BOARD_BITBOARD_H
#define BOARD_BITBOARD_H

#include <optional>

#include "board/position/position_utils.h"
#include "game/turn/game_turn_observer.h"
#include "utils/move.hpp"
#include "utils/string_utils.h"

class Position : public GameTurnObserver {
 public:
  Position();
  virtual ~Position() = default;

  void move(const Move &m);
  void update_turn(const Color &p_info);
  void undo_move(const Move &m);
  void move_piece(const Piece p, const Square from, const Square to);
  Bitboard operator[](Color c);
  bool is_occupied_at_square(const Square pos);
  void set_piece_at_square(Piece p, Square pos);
  void clear_piece_at_square(Piece p, Square pos);
  void clear();
  void clear_square_at_pos(Square sq);
  const Piece &get_piece_at_square(Square sq) const;
  Square get_king_position(Color c);
  void update_king_position(Color c, const Square &pos);
  void update_king_position(const Move &mv);
  void update_half_moves(const Move &m);
  void update_full_moves();
  int get_half_moves();
  int get_full_moves();
  void set_castle_permission(CastlePermission perm);
  const unsigned int &get_castle_permission();
  void remove_castle_permission(const CastlePermission &perm);
  void set_en_passant_square(Square sq);
  const Square &get_en_passant_square();
  CastlePermission get_castle_permission(Move &m);
  Color side_to_move() const;
  void parse_fen(const string &fen);
  string fen(Position &p);

 private:
  char get_side_turn(const Color &c);
  string get_castling_rights_string(unsigned int castle_perm);
  string get_en_passant_square_string(const Square en_passant_sq);
  bool is_number(char c);
  void add_empty_space(string &fen, int &space);
  BoardSquares m_pieces_pos{EMPTY};
  Square en_passant_pos{SquareNull};
  unsigned int castle_perm{NO_CASTLING};

  const unordered_map<CastleSquares, CastlePermission> m_white_permission{
      {WK_CA_KING_SIDE_END_POS, WKCA},
      {WK_CA_QUEEN_SIDE_END_POS, WQCA},
  };

  const unordered_map<CastleSquares, CastlePermission> m_black_permission{
      {BK_CA_KING_SIDE_END_POS, BKCA},
      {BK_CA_QUEEN_SIDE_END_POS, BQCA},
  };
  const unordered_map<Color,
                      const unordered_map<CastleSquares, CastlePermission>>
      m_castle_permission{
          {WHITE, m_white_permission},
          {BLACK, m_black_permission},
      };

  int half_moves{0};
  int full_moves{1};
  std::array<Square, Color::SIZE> king_position{SquareNull};
  std::array<Bitboard, Color::SIZE> m_occupancies{ZERO};
  Color m_side_to_move{NONE};
  static const unordered_map<char, CastlePermission> m_castle_permision;
};

#endif /* BOARD_BITBOARD_H */
