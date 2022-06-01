#ifndef INPUT_H
#define INPUT_H
#include <string>

using std::string;

class Input {
 public:
  Input() {}
  virtual ~Input() {}
  virtual const string& get_input() = 0;

 protected:
  string m_input = "quit";
};

#endif /* INPUT_H */
