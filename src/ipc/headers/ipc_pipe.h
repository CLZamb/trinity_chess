#ifndef IPC_PIPE_H
#define IPC_PIPE_H

#include "cu_pipe.h"
#include <iostream>
#include <string>

using std::cerr;
using std::endl;
using std::string;

enum processes_type {
  parent = 1,
  child = 0,
  error = -1,
};

class IpcPipe {
 public:
    IpcPipe();
    virtual ~IpcPipe();

    void _init();
    string request(string sending);

 private:
    CuPipe read_pipe;
    CuPipe write_pipe;
    CuPipe* parent_read_end;
    CuPipe* parent_write_end;
    CuPipe* child_read_end;
    CuPipe* child_write_end;

    string parent_read();
    void parent_write(string message);

    string chidl_read();
    void child_write(string message);

    void close_parent_ends();
    void close_child_ends();
    void parent_process();
    void child_process();
};

#endif /* IPC_PIPE_H */
