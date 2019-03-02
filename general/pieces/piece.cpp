#include "piece.h"

Piece::Piece(std::string pieceColor, U64 bb)
  : m_colorPiece(pieceColor), m_bbPiece(bb) {
    for (int i = 0; i < 64; ++i) {
      SetMask[i] = 0ULL;
      ClearMask[i] = 0ULL;
    }

    for (int i = 0; i < 64; ++i) {
      SetMask[i] |= (1ULL << i);
      ClearMask[i] = ~SetMask[i];
    }
  }
Piece::~Piece() {}
std::string Piece::getColorPiece() { return m_colorPiece; }
U64 Piece::getPieceBB() { return m_bbPiece; }
