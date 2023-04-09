#ifndef DEFAULT_CONFIG_H
#define DEFAULT_CONFIG_H

#include "IConfiguration.h"

class DefaultConfiguration : public IConfiguration {
public:
  DefaultConfiguration();
  virtual ~DefaultConfiguration() {}

  void get_new_configuration();
  PlayersConfig& get_players_config() override;
  virtual InputType get_input_type() override;

private:
  void get_players_type();
  void get_players_color();

  InputType m_menu_input = InputType::Keyboard;
  PlayersConfig m_players_config;
};

#endif
