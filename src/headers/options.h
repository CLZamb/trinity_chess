#ifndef OPTIONS_H
#define OPTIONS_H

#include "players_selections.h"
#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Options {
public:
  enum Start_or_quit {
    Start = 1,
    Quit = 2,
  };
  Options() {}
  virtual ~Options() {}
  int get_selected_option(vector<int> opts) {

    cout << "\t\tchoose one of the options ("
      << opts.front() << "-"
      << opts.back() << "): ";

    int input = -1;
    bool valid_option = false;

    while (!valid_option) {
      cin >> input;
      valid_option = check_valid_option(input, opts);

      if (!valid_option) {
        cout << "invalid option try again!" << endl;
        cin.clear();
        cin.ignore();
      }
    }

    cin.clear();
    cin.ignore();
    return input;
  }

  int get_players_options() {
    int opt =
      get_selected_option(m_players_selections.get_configurations_options());

    return opt;
  }

  std::pair<Player::Type, Player::Type> get_players_selection(int opt) {
    return m_players_selections.get_pair_players_type(
        static_cast<PlayersSelections::Players_configuration>(opt));
  }

private:
  bool check_valid_option(int i, const vector<int>& opts) {
    return find(opts.begin(), opts.end(), i) != opts.end();
  }
  PlayersSelections m_players_selections;

};

#endif /* OPTIONS_H */
// int Game::get_selected_option(vector<int> opts) {
//   std::cout << "\t\tchoose one of the options ("
//     << opts.front() << "-"
//     << opts.back() << "): ";
//
//   int input = -1;
//   bool valid_option = false;
//
//   while (!valid_option) {
//     std::cin >> input;
//     valid_option = check_valid_option(input, opts);
//
//     if (!valid_option) {
//       cout << "invalid option try again!" << endl;
//       std::cin.clear();
//       std::cin.ignore();
//     }
//   }
//
//   std::cin.clear();
//   std::cin.ignore();
//   return input;
// }
