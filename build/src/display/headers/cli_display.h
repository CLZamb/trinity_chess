#ifndef CLI_DISPLAY_H
#define CLI_DISPLAY_H

#include <vector>
#include <string>
#include "display.h"
#include "../../../include/common/headers/common.h"
#include "pane.h"
#include "gui_controller.h"

using std::vector;
using std::string;

enum Options {
  Begin_Options = 0,
  Player_vs_Player,
  Player_vs_Cpu,
  Cpu_vs_Cpu,
  Game_Over,
  Credits,
  End_Options,
};

enum Playertype : int {
  HUMAN, CPU
};

class CliDisplay {
 public:
    explicit CliDisplay(GuiController*);
    virtual ~CliDisplay();
    void _init();
    void print_message(Msg message);
    void set_board_players(Playertype p1, Playertype p2);
    void set_game_mode(int option);
    void print_pane();

    friend std::ostream& operator<<(std::ostream& os, CliDisplay& c);

    void set_checkmate_true() {
      checkmate = true;
    }

    bool is_checkmate();
    int get_player_game_option_selection();

 private:
    GuiController* const p_gui_c;
    bool checkmate = false;
    int get_option(int from, int to);
    vector<string> current_display{44};
};

#endif /* CLI_DISPLAY_H */
