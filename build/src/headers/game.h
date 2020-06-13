#ifndef GAME_H
#define GAME_H
#include <unistd.h>
#include "../board/headers/info.h"
#include "../display/headers/cli_display.h"
#include "../search/headers/uci.h"
#include "../ipc/headers/ipc_pipe.h"
#include "../board/headers/board.h"
#include "../display/headers/gui_controller.h"
// #include "../headers/pane.h"

class Game {
 public:
    Game();
    virtual ~Game();
    void start();
 private:
    GuiController m_gui;
    Board m_board;
    IpcPipe m_ipc_search;
    Info m_info;
    CliDisplay m_display;

    void _init();
    void play();
};

#endif /* GAME_H */
