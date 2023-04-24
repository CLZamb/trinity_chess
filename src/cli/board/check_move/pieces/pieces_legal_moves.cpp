#include "pieces_legal_moves.h"
#include "pawn.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"
#include "knight.hpp"

PiecesLegalMoves::PiecesLegalMoves() :
  m_rook_magic_bitboard(m_magic_bitboard),
  m_queen_magic_bitboard(m_magic_bitboard),
  m_bishop_magic_bitboard(m_magic_bitboard)
{

  create_all_pieces();
}

PiecesLegalMoves::~PiecesLegalMoves() {
  for (auto& i : m_pieces)
    delete i;
}

void PiecesLegalMoves::create_all_pieces() {
  // creating black pieces
  make_pawn(BLACK);
  make_rook(BLACK);
  make_bishop(BLACK);
  make_queen(BLACK);
  make_king(BLACK);
  make_knight(BLACK);

  // creating white pieces
  make_pawn(WHITE);
  make_rook(WHITE);
  make_bishop(WHITE);
  make_queen(WHITE);
  make_king(WHITE);
  make_knight(WHITE);
}

PieceBase* PiecesLegalMoves::operator[](Piece type) {
  return m_pieces[type];
}

void PiecesLegalMoves::make_pawn(const Color C) {
  if (C == BLACK)
    m_pieces[bP] = new Pawn<BLACK>;
  else
    m_pieces[wP] = new Pawn<WHITE>;
}

void PiecesLegalMoves::make_rook(const Color C) {
  if (C == BLACK)
    m_pieces[bR] = new Rook<BLACK>(m_rook_magic_bitboard);
  else
    m_pieces[wR] = new Rook<WHITE>(m_rook_magic_bitboard);
}

void PiecesLegalMoves::make_bishop(const Color C) {
  if (C == BLACK)
    m_pieces[bB] = new Bishop<BLACK>(m_bishop_magic_bitboard);
  else
    m_pieces[wB] = new Bishop<WHITE>(m_bishop_magic_bitboard);
}
//
void PiecesLegalMoves::make_queen(const Color C) {
  if (C == BLACK)
    m_pieces[bQ] = new Queen<BLACK>(m_queen_magic_bitboard);
  else
    m_pieces[wQ] = new Queen<WHITE>(m_queen_magic_bitboard);
}

void PiecesLegalMoves::make_king(const Color C) {
  if (C == BLACK)
    m_pieces[bK] = new King<BLACK>;
  else
    m_pieces[wK] = new King<WHITE>;
}

void PiecesLegalMoves::make_knight(const Color C) {
  if (C == BLACK)
    m_pieces[bN] = new Knight<BLACK>;
  else
    m_pieces[wN] = new Knight<WHITE>;
}
