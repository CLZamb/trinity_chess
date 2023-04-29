#ifndef PLAYER_CONFIG_H
#define PLAYER_CONFIG_H

#include <array>
#include "game/game_typedefs.h"

class PlayersConfig {
 public:
  PlayersConfig();
  PlayersConfig(PlayerType, PlayerType);

  void set_type(Color c, PlayerType t);
  PlayerType get_type(Color c);

 private:
  PlayerType type{PlayerType::Human};
  std::array<PlayerType, Color::SIZE> player{
      {PlayerType::Human, PlayerType::Human}};
};

#endif /* PLAYER_CONFIG_H */
