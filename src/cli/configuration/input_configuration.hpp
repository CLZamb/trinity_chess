#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H

#include "ui/menu_window/menu_window.hpp"
#include "IConfiguration.h"

class InputConfiguration : public IConfiguration {
public:
  InputConfiguration() {};

  void get_configuration() {
    get_players_type();
    get_players_color();
  }

  PlayersConfig& get_players_config() override {
    return m_players_config;
  }

  BoardConfig& get_board_config() override {
    return m_board_config;
  }

private:
  void get_players_type() {
    MenuWindow<PlayersConfig> player_menu(
      m_board_config.get_input_type(),
      "Select Players", 
      {
        {1, "Human vs Human",       {PlayerType::Human, PlayerType::Human}},
        {2, "Human vs Computer",    {PlayerType::Human, PlayerType::Cpu}},
        {3, "Computer vs Computer", {PlayerType::Cpu,   PlayerType::Cpu}},
      }
    );

    player_menu.print();
    m_players_config = player_menu.select_option();
   }

  void get_players_color() {
    MenuWindow<Color> player_menu  (
    m_board_config.get_input_type(),
      "Select Color", {
        {1, "WHITE", WHITE},
        {2, "BLACK", BLACK}}
    );

    player_menu.print();
    Color initial_color = player_menu.select_option();
    m_players_config.set_initial_color(initial_color);
  }

  BoardConfig m_board_config;
  PlayersConfig m_players_config;
};

#endif /* INPUT_CONFIGURATION_H */
