#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "configuration/headers/players_configuration.h"

class Configuration {
public:
  Configuration();
  PlayersConfig& get_players_info();

protected:
  PlayersConfig m_p_config;
  // GameConfig m_g_config;
  // BoardConfig b_config;
};

#endif /* CONFIGURATION_H */
