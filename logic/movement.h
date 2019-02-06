#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"
#include <regex>

class Movement {
private:
  struct History {
    Piece *piece;
    Piece *capturedPiece;
    Position start;
    Position end;
  };
  vector<History> prevMoves;
  Board *m_board;
  Player **m_currentPlayerTurn = nullptr;
  bool checkmate;
  bool isValidPosition(Position pos);
  bool hasCollision(Position from, Position to);
  Piece *takePiece(Position pos);
  Piece *capturePiece(Position pos);
  void capturePiece(Piece *capturedPiece);

  class Move {
  private:
    Position fromPos, toPos;
    bool validInput = false;

    std::vector<std::string> scan(std::string, const std::regex);

  public:
    Move();
    Move(std::string);
    virtual ~Move();
    void setNextMove(std::string);
    Position getPosFrom();
    Position getPosTo();
    bool isValidInput();
  };

public:
  class MoveGenerator {
  private:
    Movement *movement;
    std::string bestMove = "quit";
    int negamax(int, int, int);

  public:
    MoveGenerator(Movement *movement) : movement(movement) {}
    std::string getBestMove();
    void getPossibleMoves(std::vector<std::string> &);
    int evaluateBoard();
  };

  Movement(Board *, Player **turn);
  virtual ~Movement();
  void movePiece(std::string newmove);
  void undoLastMove();
  bool isValidMove(std::string newmove);
  bool getCheckmate() { return checkmate; }
  void generateMove();
  void changeTurn();
};

// typedef std::vector<Movement::Move> MoveSet;

#endif /* MOVEMENT_H */
