#include "headers/input_configuration.h"

InputConfiguration::InputConfiguration() : Configuration(m_input) {}

void InputConfiguration::get_configuration() {
  get_players_type();
  get_players_color();
}

void InputConfiguration::get_players_type(){
  Menu<PlayersConfig> player_menu ({
      {1, "Human vs Human", {PlayerInfo::Human, PlayerInfo::Human}},
      {2, "Human vs Cpu", {PlayerInfo::Human, PlayerInfo::Cpu}},
      {3, "Cpu vs Cpu", {PlayerInfo::Cpu, PlayerInfo::Cpu}},
  });

  player_menu.set_title("Select Players");
  player_menu.print();

  m_p_config = player_menu.select_option(m_input);
}

void InputConfiguration::get_players_color() {
  Menu<Color> player_menu  ({
      {1, "WHITE", WHITE},
      {2, "BLACK", BLACK}
  });

  player_menu.set_title("Select Color");
  player_menu.print();

  Color c = player_menu.select_option(m_input);

  m_p_config.set_color(GameTurn::player_1, c);
  m_p_config.set_color(GameTurn::player_2, c == BLACK ? WHITE :  BLACK);
}
