// File: player.h
#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <string>

class Player {
private:
  std::string colorSide;

public:
  Player();
  explicit Player(std::string);
  virtual ~Player();
  void remainingPieces();
  std::string getColor() { return colorSide; }
};

#endif /* PLAYER_H */
