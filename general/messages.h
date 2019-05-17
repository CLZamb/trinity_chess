#ifndef MESSAGES_H
#define MESSAGES_H
#include "Idisplay.h"

class Messages : public IDisplay {
public:
  Messages();
  ~Messages() {}

  void print();

  static string m_nextMessage;
private:
  static const char* p_welcome_message;
  static const char* p_start_message;
  static const char* p_game_over;
};

#endif /* MESSAGES_H */
