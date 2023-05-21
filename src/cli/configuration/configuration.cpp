#include "configuration.h"
#include "configuration/file_configuration.hpp"
#include "menu/menu_window/menu_window.hpp"

Configuration::Configuration() {
}

void Configuration::get_new_configuration() {
  get_players_type();
  get_players_color();
}

PlayersConfig& Configuration::get_players_config() {
  return m_players_config;
}

BoardConfigInfo& Configuration::get_board_config() {
  return m_board_config;
}

InputType Configuration::get_input_type() {
  return m_input_type;
}

void Configuration::get_players_type() {
  MenuWindow<PlayersConfig> player_menu(
    m_input_type,
    "Select Players", {
      {1, "Human vs Human",       {PlayerType::Human, PlayerType::Human}},
      {2, "Human vs Computer",    {PlayerType::Human, PlayerType::Cpu}},
      {3, "Computer vs Computer", {PlayerType::Cpu,   PlayerType::Cpu}},
    }
  );

  player_menu.print();
  m_players_config = player_menu.select_option();
}

void Configuration::get_players_color() {
  MenuWindow<Color> player_menu(
    m_input_type,
    "Select Color", {
      {1, "WHITE", WHITE},
      {2, "BLACK", BLACK}}
  );

  player_menu.print();
  Color initial_color = player_menu.select_option();
  m_board_config.initial_side = initial_color;
}

void Configuration::set_board_configuration(const BoardConfigInfo& board_file_info) {
  m_board_config = board_file_info;
}

void Configuration::get_config_from_file(
                        const std::string &file_name) {
  BoardConfigInfo board_info = FileInput::from_json_file(file_name);
  set_board_configuration(board_info);
}
