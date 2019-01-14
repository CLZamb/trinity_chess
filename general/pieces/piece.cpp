#include "piece.h"

Piece::Piece(Player *side) : pPlayer(side) {}
Piece::~Piece() {}

Position *Piece::getPosition() { return &pos; }
