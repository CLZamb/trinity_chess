#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"

class Movement {
private:
  Board *m_board;
  Player **m_currentPlayerTurn = nullptr;
  bool checkmate;

public:
  Movement(Board *, Player **turn);
  virtual ~Movement();
  void movePiece(Position from, Position to);
  bool isValidMove(Position from, Position to);
  bool hasCollision(Position from, Position to);
  bool getCheckmate() { return checkmate; }
  void generateMove();
};

#endif /* MOVEMENT_H */
