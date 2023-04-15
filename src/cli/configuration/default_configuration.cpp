#include "default_configuration.h"
#include "ui/graphics/menu/menu.hpp"

DefaultConfiguration::DefaultConfiguration() {
  m_players_config.set_initial_color(Color::WHITE);
}

void DefaultConfiguration::get_new_configuration() {
  get_players_type();
  get_players_color();
}

PlayersConfig& DefaultConfiguration::get_players_config() {
  return m_players_config;
}

BoardConfig& DefaultConfiguration::get_board_config() {
  return m_board_config;
}

void DefaultConfiguration::get_players_type() {
  Menu<PlayersConfig> player_menu(
    m_menu_input,
    "Select Players", {
      {1, "Human vs Human",       {PlayerType::Human, PlayerType::Human}},
      {2, "Human vs Computer",    {PlayerType::Human, PlayerType::Cpu}},
      {3, "Computer vs Computer", {PlayerType::Cpu,   PlayerType::Cpu}},
    }
  );

  player_menu.print();
  m_players_config = player_menu.select_option();
}

void DefaultConfiguration::get_players_color() {
  Menu<Color> player_menu(
    m_menu_input,
    "Select Color", {
      {1, "WHITE", WHITE},
      {2, "BLACK", BLACK}}
  );

  player_menu.print();
  Color initial_color = player_menu.select_option();
  m_players_config.set_initial_color(initial_color);
}