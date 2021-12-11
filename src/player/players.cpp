#include "headers/players.h"

Players::Players() {}
Players::~Players() {}

void Players::create_players(const PlayerConfig& config) {
  player_1 = create_new_player(config.P1, WHITE);
  player_2 = create_new_player(config.P2, BLACK);

  player_1->set_opponent(player_2);
  player_2->set_opponent(player_1);
}

std::shared_ptr<Player> Players::get_player_1() { return player_1; }
std::shared_ptr<Player> Players::get_player_2() { return player_2; }
std::unique_ptr<Player>
Players::create_new_player(Player::Type type, Color color) {
  if (type == Player::Human) 
    return std::make_unique<Player>(Player(color));

  // else Playyer::CPU
  return std::make_unique<Player>(Player(color));
}
