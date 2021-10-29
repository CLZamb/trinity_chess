#ifndef PLAYERS_SELECTIONS_H
#define PLAYERS_SELECTIONS_H

#pragma once
#include <unordered_map>
#include <vector>
#include <utility>
#include "player.h"

using std::unordered_map;
using std::pair;

class PlayersSelections {
 public:
  enum Players_configuration : int {
    players_config_begin = 0,
    Human_vs_Human,
    Human_vs_Cpu,
    Cpu_vs_Cpu,
  };

  PlayersSelections() {
    keys.reserve(players_selections.size());

    for (auto kv : players_selections) {
      keys.push_back(kv.first);
    }

    reverse(keys.begin(), keys.end());
  }

  virtual ~PlayersSelections() {}

  std::pair<Player::Type, Player::Type>
    get_pair_players_type(Players_configuration selection) {
    return players_selections[selection];
  }

  const std::vector<int> get_configurations_options() { return keys; }

 private:
  unordered_map<Players_configuration, std::pair<Player::Type, Player::Type>>
    players_selections {
      {Human_vs_Human, {Player::Human, Player::Human}},
      {Human_vs_Cpu, {Player::Human, Player::Cpu}},
      {Cpu_vs_Cpu, {Player::Cpu, Player::Cpu}}
    };

  std::vector<int> keys;
};

#endif /* PLAYERS_SELECTIONS_H */
