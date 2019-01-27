// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "input.h"
#include <string>

class Player {
protected:
  std::string colorPieces;
  Player *opponent = nullptr;
  Input playerInput;

public:
  Player();
  explicit Player(std::string);
  virtual ~Player();
  void remainingPieces();
  void setOpponent(Player *opponent) { this->opponent = opponent; }
  virtual Input *getPlayerNextMove();
  std::string getColorPieces() { return colorPieces; }
  Player *getOpponent() { return opponent; }
};

#endif /* PLAYER_H */
