#ifndef GAME_OPTIONS_H
#define GAME_OPTIONS_H

#include "graphics/headers/messages.h"
#include "graphics/headers/view.h"
#include "options.h"

class GameOptions {
public:
  GameOptions();
  virtual ~GameOptions();

  string select_start_option(Options<string> opts);
  PlayerConfig select_players_config(Options<PlayerConfig> pc);

private:
  void print_message(MessageState *messages);
  Messages m_messages;
  View options_view;
};

#endif /* GAME_OPTIONS_H */
