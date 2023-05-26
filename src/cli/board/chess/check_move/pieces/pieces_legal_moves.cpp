#include "pieces_legal_moves.h"

#include "bishop.hpp"
#include "king.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "queen.hpp"
#include "rook.hpp"

PiecesLegalMoves::PiecesLegalMoves(Position& pos, Color& side)
: m_position(pos), m_side(side)
    , m_rook_magic_bitboard(m_magic_bitboard)
    , m_queen_magic_bitboard(m_magic_bitboard)
    , m_bishop_magic_bitboard(m_magic_bitboard) {
  create_all_pieces();
}

PiecesLegalMoves::~PiecesLegalMoves() {
  for (auto &i : m_pieces) delete i;
}

void PiecesLegalMoves::create_all_pieces() {
  // Black pieces
  m_pieces[bP] = new Pawn<BLACK>;
  m_pieces[bR] = new Rook<BLACK>(m_rook_magic_bitboard);
  m_pieces[bB] = new Bishop<BLACK>(m_bishop_magic_bitboard);
  m_pieces[bQ] = new Queen<BLACK>(m_queen_magic_bitboard);
  m_pieces[bK] = new King<BLACK>;
  m_pieces[bN] = new Knight<BLACK>;
  // White pieces
  m_pieces[wP] = new Pawn<WHITE>;
  m_pieces[wR] = new Rook<WHITE>(m_rook_magic_bitboard);
  m_pieces[wB] = new Bishop<WHITE>(m_bishop_magic_bitboard);
  m_pieces[wQ] = new Queen<WHITE>(m_queen_magic_bitboard);
  m_pieces[wK] = new King<WHITE>;
  m_pieces[wN] = new Knight<WHITE>;
}

PieceBase *PiecesLegalMoves::operator[](Piece type) { return m_pieces[type]; }

bool PiecesLegalMoves::check_checkmate() {
  Bitboard all_king_possible_positions{get_all_king_possible_positions()};
  int count_possible_king_moves{0}, count_king_moves_blocked{0};
  Square position;

  while (all_king_possible_positions) {
    count_possible_king_moves++;
    position = static_cast<Square>(bitUtility::pop_1st_bit(&all_king_possible_positions));
    if (can_opponent_attack_square(position)) count_king_moves_blocked++;
  }

  return count_possible_king_moves == count_king_moves_blocked;
}

Bitboard PiecesLegalMoves::get_all_king_possible_positions() {
  Square sq = m_position.get_king_position(m_side);
  return King<WHITE>::king_mask(sq);
}

bool PiecesLegalMoves::can_check(const Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  return !utils::check::is_king_piece(piece) && (is_king_piece_attacked());
}

bool PiecesLegalMoves::can_be_block_by_another_piece(const Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  if (utils::check::is_king_piece(piece)) return false;

  bool is_king_in_check{false};

  m_position.make_move(m);
  is_king_in_check = can_check(m);
  m_position.undo_move(m);

  return !is_king_in_check;
}

bool PiecesLegalMoves::is_king_piece_attacked() {
  Square sq = m_position.get_king_position(m_side);
  return can_opponent_attack_square(sq);
}

Color PiecesLegalMoves::get_opponent_player_color() {
  return m_side == WHITE ? BLACK : WHITE;
}

bool PiecesLegalMoves::can_opponent_attack_square(const Square &sq) {
  Color opposite_color = get_opponent_player_color();
  Bitboard opposite_player_bitboard =  m_position.get_occupied_side_as_bitboard(opposite_color);
  Bitboard temp_iterable_bb = opposite_player_bitboard;
  Bitboard attack_bitboard{ZERO};
  Piece pt;
  Square position{0};

  while (temp_iterable_bb) {
    position = static_cast<Square>(bitUtility::pop_1st_bit(&temp_iterable_bb));

    pt = m_position.get_piece(position);

    attack_bitboard |= m_pieces[pt]->get_attacks(opposite_player_bitboard, position);
  }

  Bitboard to_bb = ONE << sq;
  return attack_bitboard & to_bb;
}

bool PiecesLegalMoves::is_legal_move(Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  return m_pieces[piece]->is_legal_move(m, m_position);
}
