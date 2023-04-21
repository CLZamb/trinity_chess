// --------
// NOT SUPPORTED YET
// ------
// #include <iostream>
// #include <unistd.h>
// #include <termios.h>
// #include <fcntl.h>
//
// int main()
// {
//   // put the terminal in non-canonical mode
//   struct termios t;
//   tcgetattr(STDIN_FILENO, &t);
//   t.c_lflag &= ~(ICANON | ECHO);
//   tcsetattr(STDIN_FILENO, TCSANOW, &t);
//
//   // send escape sequence to request cursor position
//   std::cout << "\033[6n";
//
//   // read cursor position response
//   char c;
//   std::string response;
//   while (read(STDIN_FILENO, &c, 1) == 1)
//   {
//     if (c == 'R') // end of response
//       break;
//     response += c;
//   }
//
//   // parse cursor position from response
//   int x, y;
//   sscanf(response.c_str(), "\033[%d;%dR", &y, &x);
//
//   // print cursor position
//   std::cout << "Cursor position: x=" << x << " y=" << y << std::endl;
//
//   // restore terminal to original mode
//   t.c_lflag |= ICANON | ECHO;
//   tcsetattr(STDIN_FILENO, TCSANOW, &t);
//
//
//   std::cout << response << std::endl;
//   return 0;
// }
