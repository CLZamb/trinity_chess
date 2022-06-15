#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H
#include "configuration.h"
#include "game/headers/menu.h"
#include "input/headers/console_input.h"

class InputConfiguration : public Configuration {
public:
  InputConfiguration(Input& input);
  void get_configuration();

private:
  void get_players_type();
  void get_players_color();
  Input& m_menu_input;
};

#endif /* INPUT_CONFIGURATION_H */
