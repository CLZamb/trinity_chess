#ifndef MESSAGES_H
#define MESSAGES_H
#include "Idisplay.h"

class Messages : public IDisplay {
private:
public:
  Messages();
  ~Messages() {}

  static char *welcomeMessage;
  static char *startMessage;
  static char *gameOver;
  static string m_nextMessage;
  void print();
};

#endif /* MESSAGES_H */
