// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "move.h"
#include <iostream>
#include <piece.h>
#include <regex>
#include <string>

using std::string;
using std::vector;

class Player {
protected:
  bool validInput;
  vector<string> scan(std::string, const std::regex);
  void setNextMove(string playerInput);
  std::string m_colorPieces;
  Player *opponentPtr = nullptr;
  std::string m_nextMove;
  Move m_Move;

public:
  Player();
  explicit Player(std::string colorPieces);
  virtual ~Player();
  void setOpponent(Player *opponent) { this->opponentPtr = opponent; }
  virtual Move getPlayerNextMove();
  std::string getColorPieces() { return m_colorPieces; }
  Player *getOpponent() { return opponentPtr; }
  bool isValidMove() { return validInput; }
};

#endif /* PLAYER_H */
