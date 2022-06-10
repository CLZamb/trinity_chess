#include "headers/keyboard_input.h"

termios KeyboardInput::old;
termios KeyboardInput::current;

using std::cin;
using std::cout;

KeyboardInput::KeyboardInput() {
  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &current);

  pos[GameTurn::player_1] = A1;
  pos[GameTurn::player_2] = H8;
  m_event.set_type(InputEvent::None);
}

KeyboardInput::~KeyboardInput() { 
  tcsetattr(STDIN_FILENO, TCSANOW, &old); 
}

void KeyboardInput::update_turn(const PlayerInfo &info) {
  m_player_info = info;
}

const string &KeyboardInput::get_player_string_move() {
  cin.get();
  exit(0);
  return m_input;
}

int KeyboardInput::select_menu_option(const vector<int> &opts) {
  if (opts.size() == 0) return 0;

  m_event.set_type(InputEvent::KeyPressed);
  bool selected = false;
  vector<int>::const_iterator selected_option = opts.begin();

  InputKeys::Key key_pressed = InputKeys::quit;
  while (!selected) {
    key_pressed = InputKeys::Key(fgetc(stdin));
    switch (key_pressed) {
      case InputKeys::quit:
      case InputKeys::Quit:
        exit(EXIT_SUCCESS);
      case InputKeys::ENTER:
        selected = true;
        break;
      case InputKeys::ARROW_KEY:
        key_pressed = InputKeys::Key(get_arrow_key_pressed());
        update_current_selection(key_pressed, opts, selected_option);
        break;
      default:
        cout << "Invalid key, please use arrow keys, select with enter!\n";
        break;
    }
  }

  return *selected_option;
}

void KeyboardInput::update_current_selection(
    const InputKeys::Key &key_pressed, const vector<int> &opts,
    vector<int>::const_iterator &selected_option) {
  switch(key_pressed) {
    case InputKeys::UP:
      if(*selected_option != opts.front())
        selected_option--;
      break;
    case InputKeys::DOWN:
      if(*selected_option != opts.back())
        selected_option++;
      break;
    default:
      return;
  }

  m_event.set_pressed_key(key_pressed);
  notify_input_event();
}

int KeyboardInput::get_arrow_key_pressed() {
  if (fgetc(stdin) != InputKeys::LEFT_BRACKET) return 0;

  int key_pressed =  fgetc(stdin);
  return key_pressed;
}

void KeyboardInput::update_listener(InputObserver *observer) {
  p_observer = observer;
  m_event.set_type(InputEvent::KeyboardSetup);
  notify_input_event();
}

void KeyboardInput::notify_input_event() {
  if (p_observer)
    p_observer->handle_input_event(m_event);
}
