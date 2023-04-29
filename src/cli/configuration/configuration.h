#ifndef DEFAULT_CONFIG_H
#define DEFAULT_CONFIG_H

#include "IConfiguration.h"
#include "configuration/IConfiguration.h"
#include "configuration/players_configuration.h"
#include "ui/input/input_types.h"

class Configuration : public IConfiguration {
public:
  Configuration();
  virtual ~Configuration() {}

  void get_new_configuration();
  PlayersConfig& get_players_config() override;
  BoardConfig& get_board_config() override;
  InputType get_input_type() override;
private:
  void get_players_type();
  void get_players_color();

  BoardConfig m_board_config;
  PlayersConfig m_players_config;
  InputType m_input_type {Keyboard};
};

#endif
