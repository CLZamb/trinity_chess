#include "headers/game.h"

Game::Game() :
  m_gui(),
  m_board(),
  m_ipc_search(),
  m_info(&m_board),
  m_display(&m_gui)
{}
Game::~Game() {}

void Game::start() {
  m_display.print_message(Welcome);

  // wait for the user to press any button to continue
  std::cin.get();

  int game_mode = m_display.get_player_game_option_selection();
  m_display.set_game_mode(game_mode);

  switch (game_mode) {
    case Game_Over:
      m_display.print_message(GameOver);
    return;
    case Credits:
      return;
    case Player_vs_Player:
    case Player_vs_Cpu:
    case Cpu_vs_Cpu:
      m_board.set_players(new Player(false), new Player(true));
      play();
      break;
    default:
      cout << "wrong option" << endl;
      break;
  }
}

void Game::_init() {
  m_gui.add_pane("board", " ┃                                                                        ┃");
  m_gui.add_pane("info", " ┃                                                          ┃");
  m_info._init(m_gui.get_pane("info"));
  m_board._init(m_gui.get_pane("board"));

  m_ipc_search._init();
  m_display._init();
}

void Game::play() {
  _init();

  // PlayerMove player_move;
  string player_move = "a1 a3";
  string cur_board_state_fen = "";

  while (!m_board.is_checkmate()) {
    if (player_move == "quit" || player_move == "exit")
      break;

    m_board.set_checkmate_true();
    m_board.make_move(player_move);
    // m_display.make_move(player_move);
    // player_move = get_player_move();
    // PlayerMove = get_player_move();
    // current_board_state = search.get_current_state();
    // m_display.set_board_state(current_board_state);
    m_board.draw_board();
    m_info.draw_info_board();
    cout << m_display;
  }
}
