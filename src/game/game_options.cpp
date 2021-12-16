#include "headers/game_options.h"
#include "player/headers/player.h"

GameOptions::GameOptions() : options_view(MessageView(&m_messages)) {}
GameOptions::~GameOptions() {}


void GameOptions::print_message(MessageState *message) {
  m_messages.set_message(message);
  options_view.print();
}

string GameOptions::select_start_option(Options<string> opts) {
  print_message(m_messages.get_play_or_quit());
  return opts.select_option();
}

PlayerConfig GameOptions::select_players_config(Options<PlayerConfig> pc) {
  print_message(m_messages.get_players_options());
  return pc.select_option();
}

