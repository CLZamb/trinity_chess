#ifndef DEFAULT_CONFIG_H
#define DEFAULT_CONFIG_H

#include "IConfiguration.h"

class DefaultConfiguration : public IConfiguration {
public:
  DefaultConfiguration();
  virtual ~DefaultConfiguration() {}

  void get_new_configuration();
  PlayersConfig& get_players_config() override;
  BoardConfig& get_board_config() override;

private:
  void get_players_type();
  void get_players_color();

  BoardConfig m_board_config;
  PlayersConfig m_players_config;
};

#endif
