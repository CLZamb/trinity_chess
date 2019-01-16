// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <string>

class Player {
private:
  std::string colorSide;
  Player *opponent = nullptr;

public:
  Player();
  explicit Player(std::string);
  virtual ~Player();
  void remainingPieces();
  std::string getColor() { return colorSide; }
  void setOpponent(Player *opponent) { this->opponent = opponent; }
  Player *getOpponent() { return opponent; }
};

#endif /* PLAYER_H */
