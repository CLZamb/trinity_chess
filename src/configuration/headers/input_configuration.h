#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H
#include "configuration.h"
#include "game/headers/menu.h"
#include "input/headers/text_input.h"

template<typename T>
class InputConfiguration : public Configuration {
public:
  InputConfiguration(T& input) : m_menu_input(input) {};

  void get_configuration() {
    get_players_type();
    get_players_color();
  }

private:
  void get_players_type(){
    Menu<PlayersConfig> player_menu(
    m_menu_input,
      "Select Players",{
        {1, "Human vs Human",       {GameTurn::Human, GameTurn::Human}},
        {2, "Human vs Computer",    {GameTurn::Human, GameTurn::Cpu}},
        {3, "Computer vs Computer", {GameTurn::Cpu,   GameTurn::Cpu}},
      }
    );

    player_menu.print();
    m_p_config = player_menu.select_option();
  }


  void get_players_color() {
    Menu<Color> player_menu  (
    m_menu_input,
      "Select Color", {
        {1, "WHITE", WHITE},
        {2, "BLACK", BLACK}}
    );

    player_menu.print();
    Color c = player_menu.select_option();

    m_p_config.set_color(GameTurn::player_1, c);
    m_p_config.set_color(GameTurn::player_2, c == BLACK ? WHITE :  BLACK);
  }

  T& m_menu_input;
};

#endif /* INPUT_CONFIGURATION_H */
