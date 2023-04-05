#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H

#include "ui/graphics/menu/menu.hpp"
#include "IConfiguration.h"

class InputConfiguration : public IConfiguration {
public:
  InputConfiguration(InputType& input) : m_menu_input(input) {};

  void get_configuration() {
    get_players_type();
    get_players_color();
  }

  PlayersConfig& get_players_config() override {
    return m_players_config;
  }

private:
  void get_players_type(){
    Menu<PlayersConfig> player_menu(
      m_menu_input,
      "Select Players", 
      {
        {1, "Human vs Human",       {GameTurn::Human, GameTurn::Human}},
        {2, "Human vs Computer",    {GameTurn::Human, GameTurn::Cpu}},
        {3, "Computer vs Computer", {GameTurn::Cpu,   GameTurn::Cpu}},
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
    Color player = player_menu.select_option();
    Color opponent = player == BLACK ? WHITE : BLACK;

    m_players_config.set_color(GameTurn::player_1, player);
    m_players_config.set_color(GameTurn::player_2, opponent);
  }

  InputType m_menu_input;
  PlayersConfig m_players_config;
};

#endif /* INPUT_CONFIGURATION_H */
