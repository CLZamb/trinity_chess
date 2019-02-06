#include "piece.h"

Piece::Piece(std::string pieceColor) : m_colorPiece(pieceColor) {}
Piece::~Piece() {}

Position *Piece::getPosition() { return &pos; }

std::string Piece::getColorPiece() { return m_colorPiece; }
void Piece::setPosition(Position pos) { this->pos = pos; }
