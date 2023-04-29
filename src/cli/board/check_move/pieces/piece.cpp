#include "piece.h"

PieceBase::PieceBase(const Piece &type) : _m_type(type) {}

PieceBase::~PieceBase() {}

Piece PieceBase::get_piecetype() { return _m_type; }
