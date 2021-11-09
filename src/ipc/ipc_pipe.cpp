#include "headers/ipc_pipe.h"

IpcPipe::IpcPipe() {
  parent_read_end = &read_pipe;
  parent_write_end = &write_pipe;
  child_read_end = &write_pipe;
  child_write_end = &read_pipe;

  pid_t pid = fork();

  switch (pid) {
    case error:
      cerr << "fork failed" << endl;
      break;
    case child:
      child_process();
      break;
    default:  // parent
      parent_process();
      break;
  }
}

IpcPipe::~IpcPipe() {
  close_child_ends();
  close_parent_ends();
  wait(nullptr);
}

void IpcPipe::_init() {
  request("uci");
  request("isready");
}

string IpcPipe::request(string sending) {
  string message = "";
  sending += '\n';

  parent_write_end->write(sending);

  message = parent_read_end->read();
  return message;
}

string IpcPipe::parent_read() {
  return parent_read_end->read();
}

void IpcPipe::parent_write(string message) {
  parent_write_end->write(message);
}

string IpcPipe::chidl_read() {
  return child_read_end->read();
}

void IpcPipe::child_write(string message) {
  child_write_end->write(message);
}


void IpcPipe::close_parent_ends() {
  parent_read_end->close_end(READ_END);
  parent_write_end->close_end(WRITE_END);
}

void IpcPipe::close_child_ends() {
  child_read_end->close_end(READ_END);
  child_write_end->close_end(WRITE_END);
}

void IpcPipe::child_process() {
  close_parent_ends();

  child_read_end->redirect_input();
  child_write_end->redirect_output();

  const char* arguments[] = {
    
    "/Users/cristofher/desktop/practice/c++/ChessProject_v2/bin/search" ,
    // "uci",
    nullptr };
  execv(
      const_cast<char *>(arguments[0]),
      const_cast<char **>(arguments));

  // if exec fails
  cerr << "executable not found" << endl;
  close_child_ends();
  exit(EXIT_FAILURE);
}

void IpcPipe::parent_process() {
  close_child_ends();
}
