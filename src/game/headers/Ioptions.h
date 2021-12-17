#ifndef IOPTIONS_H
#define IOPTIONS_H
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::cin;
using std::unordered_map;

template<typename T>
class Ioptions {
public:
  virtual ~Ioptions();
  int get_selected_option() {}
  int select_option() {
    cout << "\t\tchoose one of the options ("
      << 0
      << " - "
      << options.size();

    int input = -1;
    bool valid_option = false;

    while (!valid_option) {
      cin >> input;
      valid_option = check_valid_option(input);

      if (!valid_option) {
        cout << "invalid option try again!" << endl;
        cin.clear();
        cin.ignore();
      }
    }

    cin.clear();
    cin.ignore();
    return input;
  }

protected:
  Ioptions();

private:
  unordered_map<int, T> options;
  bool check_valid_option(int i) {
    return options.find(i) != options.end();
  }
};

#endif /* IOPTIONS_H */
