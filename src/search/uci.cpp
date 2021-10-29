#include "headers/uci.h"
#include <fstream>
// void parse_go(string line, search_info info, Board *pos) {}
// void parse_position(string line, Board *pos) {}
using std::istringstream;
using std::skipws;
using std::ofstream;

namespace UCI {

Handler::Handler(Search* search) {
  this->search = search;
}

Handler::~Handler() {}

void Handler::loop(const string& args) {
  string cmd = args, token;

  // cout << "Trinity engine 2.1 by Deux" << endl;

  do {
    if (args.empty() && !getline(cin, cmd))  // Block here waiting for input
      cmd = "quit";

    istringstream is(cmd);

    // clear possible previous entries
    token.clear();

    is >> skipws >> token;

    if (token == "quit") break;
    else if (token == "uci") uci_command();
    else if (token == "isready") is_ready_command();
    else if (token == "setoption") set_option_command(is);
    else if (token == "ucinewgame") uci_new_game_command();
    else if (token == "position") position_command(is);
    else if (token == "go") go_command(is);
    else if (token == "stop") stop_command();
    else if (token == "ponderhit") ponder_hit_command();
    else if (token == "register") register_command();
    else if (token == "debug") debug_command();
    else if (token == "noop") /* noop */;
    else
      cout << "Unknown UCI command: { \"" << token << "\" } "<< endl;
  } while (token != "quit" && args.empty());  // args runs one time
}

void Handler::uci_command() {
  cout << "id name is trinity engine" << std::endl;
  cout << "id author Deux" << endl;
  cout << "uciok" << endl;
}

void Handler::is_ready_command() {
  cout << "is ready" << endl;
}

void Handler::set_option_command(std::istringstream &inStream) {}
void Handler::uci_new_game_command() {}
void Handler::position_command(std::istringstream &inStream) {}
void Handler::go_command(std::istringstream &inStream) {}
void Handler::stop_command() {}
void Handler::ponder_hit_command() {}
void Handler::register_command() {}
void Handler::debug_command() {}
void Handler::noop() {}
}  // namespace UCI
