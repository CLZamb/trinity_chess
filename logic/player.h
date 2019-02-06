// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <iostream>
#include <piece.h>
#include <string>

class Player {
protected:
  std::string m_colorPieces;
  Player *opponentPtr = nullptr;
  std::string m_nextMove;
  PiecesSetPtr m_pieces;

public:
  Player();
  explicit Player(std::string colorPieces);
  virtual ~Player();
  void setOpponent(Player *opponent) { this->opponentPtr = opponent; }
  void setPieces(PiecesSetPtr);
  PiecesSetPtr getPieces();
  virtual std::string getPlayerNextMove();
  std::string getColorPieces() { return m_colorPieces; }
  Player *getOpponent() { return opponentPtr; }
};

#endif /* PLAYER_H */
