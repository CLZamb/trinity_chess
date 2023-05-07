#ifndef ICONFIGURATION_H
#define ICONFIGURATION_H

#include "configuration/board_info.h"
#include "players_configuration.h"
#include <string>

class IConfiguration {
public:
  virtual PlayersConfig& get_players_config() = 0;
  virtual BoardInfo& get_board_config() = 0;
  virtual InputType get_input_type() = 0;
  // GameConfig& get_players_config() = 0;
};

#endif /* CONFIGURATION_H */
