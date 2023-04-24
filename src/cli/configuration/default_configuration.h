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
  const std::string& get_fen() override {return m_start_fen; }

private:
  void get_players_type();
  void get_players_color();

  const std::string m_start_fen = "6rk/8/8/8/7R/8/8/7K w - - 0 1";
  BoardConfig m_board_config;
  PlayersConfig m_players_config;
};

#endif
