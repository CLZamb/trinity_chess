#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H

#include "ui/graphics/menu/menu.hpp"
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

  virtual InputType get_input_type() override {
    return m_menu_input;
  }

private:
  void get_players_type() {
    Menu<PlayersConfig> player_menu(
      m_menu_input,
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
    Menu<Color> player_menu  (
    m_menu_input,
      "Select Color", {
        {1, "WHITE", WHITE},
        {2, "BLACK", BLACK}}
    );

    player_menu.print();
    Color initial_color = player_menu.select_option();
    m_players_config.set_initial_color(initial_color);
  }

  InputType m_menu_input = InputType::Keyboard;
  PlayersConfig m_players_config;
};

#endif /* INPUT_CONFIGURATION_H */
