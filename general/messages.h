#ifndef MESSAGES_H
#define MESSAGES_H
#include "Idisplay.h"

class Messages : public IDisplay {
private:
public:
  Messages();
  ~Messages() {}

  static char* p_welcome_message;
  static char* p_start_message;
  static char* p_game_over;
  static string m_nextMessage;
  void print();
};

#endif /* MESSAGES_H */
