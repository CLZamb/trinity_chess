#ifndef INPUT_CONFIGURATION_H
#define INPUT_CONFIGURATION_H
#include "configuration.h"
#include "game/headers/menu.h"

class InputConfiguration : public Configuration {
public:
  InputConfiguration();
  void get_player_input_configuration();

private:
  void get_players_type();
  void get_players_color();
};

#endif /* INPUT_CONFIGURATION_H */
