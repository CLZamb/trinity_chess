#ifndef BOARD_BITBOARD_H
#define BOARD_BITBOARD_H


#include "board/board_representation/board_utils.h"
#include "game/turn/game_turn_observer.h"
#include "utils/move.hpp"
#include "utils/string_utils.h"
#include <optional>

class Position : public GameTurnObserver {
public:
  Position();
  virtual ~Position() = default;

  void move(const Move &m);
  void update_turn(const PlayerInfo &p_info);
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

private:
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

  // Castling Rights
  unsigned int castle_perm{NO_CASTLING};
  // En passant target square
  Square en_passant_pos{SquareNull};
  //  Halfmove Clock
  int half_moves{0};
  int full_moves{1};
  std::array<Square, Color::SIZE> king_position{SquareNull};
  std::array<Bitboard, Color::SIZE> m_occupancies{ZERO};
  std::array<Bitboard, PieceType::PIECE_TYPE_SIZE> m_pieces_bitboard{ZERO};
  // Piece placement on the Chessboard as
  // considered by the Board Representation
  BoardSquares m_pieces_pos{EMPTY};
  // Side to move
  Color m_side_to_move{NONE};
};

#endif /* BOARD_BITBOARD_H */
