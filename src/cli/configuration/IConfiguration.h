#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "players_configuration.h"
#include "ui/input/input_types/input_types.h"

class IConfiguration {
public:
  virtual PlayersConfig& get_players_config() = 0;
  virtual InputType get_input_type() = 0;
  // GameConfig& get_players_config() = 0;
  // BoardConfig& get_players_config() = 0;
};

#endif /* CONFIGURATION_H */
