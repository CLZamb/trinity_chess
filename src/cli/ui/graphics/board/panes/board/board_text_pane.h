#ifndef BOARD_TEXT_PANE_H
#define BOARD_TEXT_PANE_H

#include "ui/graphics/board/panes/board/board_pane.h"
#include "ui/input/board/text/text_input_board.h"

class BoardTextPane : public BoardPane {
public:
  BoardTextPane(const string &fen, shared_ptr<TextInputBoard> p)
      : BoardPane(fen) {
    p->bind(Keyboard::ENTER, &BoardTextPane::handle_string_input, this);
  }

  virtual ~BoardTextPane() {}

  virtual void update() override {
    BoardPane::update_board_drawing(); 
  }

  virtual void make_move(const Move &mv) override { 
    BoardPane::make_move(mv); 
  }

  virtual void update_turn(const PlayerInfo &) override {}

  bool has_events() override { return true; }

  string get_string() override { return call_back; }

  void handle_string_input(KeyCode::Key) {
    std::cout << "handling " << std::endl;
    call_back = "quit";
    std::cout << " >> ";
    call_back = m_text.get_string_input();
  }

private:
  string call_back{""};
  TextInputBase m_text;
};

#endif /* BOARD_TEXT_PANE_H */
