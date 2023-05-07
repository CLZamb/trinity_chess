#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "IConfiguration.h"
#include "configuration/IConfiguration.h"
#include "configuration/players_configuration.h"
#include "input/input_types.h"

class Configuration : public IConfiguration {
public:
  Configuration();
  virtual ~Configuration() {}

  void set_board_configuration(const BoardConfigInfo& board_fiel_info);
  void set_board_configuration();
  void get_new_configuration();
  PlayersConfig& get_players_config() override;
  BoardConfigInfo& get_board_config() override;
  InputType get_input_type() override;
  
private:
  void get_players_type();
  void get_players_color();

  BoardConfigInfo m_board_config;
  PlayersConfig m_players_config;
  InputType m_input_type{InputType::Text};
};

#endif /* CONFIGURATION_H */
