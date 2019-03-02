#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using std::string;
using std::vector;

class Movement {
private:
  Board *m_board;
  Player **m_currentPlayerTurn = nullptr;
  bool checkmate;
  bool isValidPosition(Position pos);
  bool checkMove(Piece* currentPiece, int from, int to);
  Piece *takePiece(int pos);
  Piece *capturePiece(int pos);
  void capturePiece(Piece *capturedPiece);
  vector<Move> prevMoves;

public:
  Movement(Board *, Player **turn);
  virtual ~Movement();
  void movePiece(Move newmove);
  void undoLastMove();
  bool isValidMove(Move newmove);
  bool getCheckmate() { return checkmate; }
  void generateMove();
  void changeTurn();

  class MoveGenerator {
    private:
      std::map<Move, int> temp;
      Movement *movement;
      string bestMove = "quit";
      int negamax(int, int, int, int);

    public:
      MoveGenerator(Movement *movement) : movement(movement) {}
      Move getBestMove();
      void getPossibleMoves(MoveList*);
      int evaluateBoard();
  };
};

// typedef vector<Movement::Move> MoveSet;

#endif /* MOVEMENT_H */
