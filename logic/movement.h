#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"
#include <algorithm>
#include <functional>
#include <map>
#include <regex>
#include <set>

using std::string;
using std::vector;

class Movement {
private:
  // struct History {
  //   Piece *piece;
  //   Piece *capturedPiece;
  //   Position start;
  //   Position end;
  // };
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
    char piece_promoted_to;
    bool castle;
    bool en_passant;
    Position fromPos, toPos;
    bool validInput = false;

    vector<string> scan(std::string, const std::regex);

  public:
    Position from;
    Position to;
    Piece *piece;
    Piece *capturedPiece;
    Move();
    Move(string);
    Move(Piece *piece, Piece *capturedPiece, Position start, Position end);
    virtual ~Move();
    void setNextMove(string);
    Position getPosFrom();
    Position getPosTo();
    bool isValidInput();
  };

  vector<Move> prevMoves;

public:
  class MoveGenerator {
  private:
    std::map<string, int> temp;
    Movement *movement;
    string bestMove = "quit";
    int minimax(int, bool);
    int negamax(int, int, int, int);

  public:
    MoveGenerator(Movement *movement) : movement(movement) {}
    string getBestMove();
    void getPossibleMoves(vector<string> &);
    int evaluateBoard();
    void sortMoves(vector<string> &);
  };

  Movement(Board *, Player **turn);
  virtual ~Movement();
  void movePiece(string newmove);
  void undoLastMove();
  bool isValidMove(string newmove);
  bool getCheckmate() { return checkmate; }
  void generateMove();
  void changeTurn();
};

// typedef vector<Movement::Move> MoveSet;

#endif /* MOVEMENT_H */
