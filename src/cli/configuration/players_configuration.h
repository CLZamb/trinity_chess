#ifndef PLAYER_CONFIG_H
#define PLAYER_CONFIG_H

#include "game/players/player_info.hpp"
#include <array>

class PlayersConfig {
public:
  PlayersConfig();
  PlayersConfig(PlayerType, PlayerType);

  void set_initial_color(Color c);
  Color get_initial_color();

  void set_type(Color c, PlayerType t);
  PlayerType get_type(Color c);
  PlayerInfo get_player_info(Color);

private:
  std::array<PlayerInfo, Color::SIZE> player {{
    {Color::WHITE, PlayerType::Human},
    {Color::BLACK, PlayerType::Human}
  }};

  Color m_initial_side{Color::WHITE};
};

#endif /* PLAYER_CONFIG_H */
