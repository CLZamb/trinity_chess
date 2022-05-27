#ifndef VIEW_H
#define VIEW_H

#include<string>
#include<iostream>
#include"../../board/headers/board_with_info.h"
#include"window.h"
#include"messages.h"

using std::string;
using std::cout;
using std::endl;

class View {
  public:
    View(string name);
    void print();

    static string Get_name();
  protected:
    Window window_view;
  private:
    static string name;
};

class BoardView : public View {
  public:
    BoardView(BoardWithInfo * board) : View("Board") {
      window_view.add_pane(board->get_board_drawing(), Window::Middle_pane);
      window_view.add_pane(board->get_info_drawing(), Window::Right_pane);
    }
};

class MessageView : public View {
  public: 
    MessageView(Messages* messages) : View("Messages") {
      window_view.add_pane(messages, Window::Left_pane);
    }
};
 
#endif /* VIEW_H */
