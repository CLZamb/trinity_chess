#ifndef CU_PIPE_H
#define CU_PIPE_H

#include<unistd.h>
#include<cstdio>
#include<string>
#include<array>

using std::string;
using std::array;

enum w_r {
  READ_END = 0,
  WRITE_END = 1,
  FD_SIZE = 2,
  BUFFER_SIZE = 1024,
};

class CuPipe {
 public:
    CuPipe();
    virtual ~CuPipe();

    void redirect_output();
    void redirect_input();

    string read();
    void write(string message);

    void close_end(int end);
    int* get_end(int end);
 private:
    array<int, FD_SIZE> m_handles;
};

#endif /* CU_PIPE_H */
