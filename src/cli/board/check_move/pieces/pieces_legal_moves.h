#ifndef PIECES_H
#define PIECES_H

#include "magic_bitboard.h"
#include "piece.h"

class PiecesLegalMoves {
 public:
  PiecesLegalMoves(Position &pos, Color &side);
  virtual ~PiecesLegalMoves();
  PieceBase *operator[](Piece type);

  bool is_king_piece_attacked();
  bool can_opponent_attack_square(const Square &to);
  bool is_legal_move(Move &);
  Bitboard get_all_king_possible_positions();

 private:
  Color get_opponent_player_color();
  bool check_checkmate();
  bool can_check(const Move &m);
  bool can_be_block_by_another_piece(const Move &m);
  void create_all_pieces();
  Position &m_position;
  Color &m_side;
  MagicBitboard m_magic_bitboard;
  RookMagicBitboard m_rook_magic_bitboard;
  QueenMagicBitboard m_queen_magic_bitboard;
  BishopMagicBitboard m_bishop_magic_bitboard;
  std::array<PieceBase *, 13> m_pieces{nullptr};
  static const int m_max_size = 13;
};

#endif /* ifndef PIECES_H */
