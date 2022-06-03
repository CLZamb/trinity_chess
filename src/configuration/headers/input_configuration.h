#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H
#include "configuration.h"
#include "game/headers/menu.h"
#include "player/headers/console_input.h"

class InputConfiguration : public Configuration {
public:
  InputConfiguration();
  void get_configuration();
  Input& get_input_manager();

private:
  void get_players_type();
  void get_players_color();
  ConsoleInput m_input;
};

#endif /* INPUT_CONFIGURATION_H */
