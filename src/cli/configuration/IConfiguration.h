#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "players_configuration.h"

class IConfiguration {
public:
  virtual PlayersConfig& get_players_config() = 0;
  // GameConfig& get_players_config() = 0;
  // BoardConfig& get_players_config() = 0;
};

#endif /* CONFIGURATION_H */
