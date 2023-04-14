#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "configuration/board_configuration.h"
#include "players_configuration.h"

class IConfiguration {
public:
  virtual PlayersConfig& get_players_config() = 0;
  virtual BoardConfig& get_board_config() = 0;
  // GameConfig& get_players_config() = 0;
};

#endif /* CONFIGURATION_H */
