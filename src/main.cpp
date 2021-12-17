#include "game/headers/game.h"
#include "game/headers/menu.h"

void play() {
  Menu<PlayerConfig> player_menu ({
      {Player::Human, Player::Human},
      {Player::Human, Player::Cpu},
      {Player::Cpu, Player::Cpu}});

  player_menu.print_players_options();

  Game game(player_menu.select_option());
  game.start();
}

int main(/*int argc, char *argv[]*/) {
  string play_str = "Play", quit = "Quit";
  Menu<string> start_menu ({play_str, quit});

  start_menu.print_play_or_quit();

  if (start_menu.select_option() == play_str) {
    play();
  }

  return 0;
}
