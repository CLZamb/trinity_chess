#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "configuration/headers/players_configuration.h"
#include "player/headers/input.h"

class Configuration {
public:
  Configuration(Input&);
  PlayersConfig& get_players_info();
  Input& get_input_manager();

protected:
  PlayersConfig m_p_config;
  Input& m_input;
  // GameConfig m_g_config;
  // BoardConfig b_config;
};

#endif /* CONFIGURATION_H */
