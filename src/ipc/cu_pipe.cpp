#include"headers/cu_pipe.h"

CuPipe::CuPipe() {
  if (pipe(m_handles.data()) < 0) {
    perror("Pipe 1 failed");
    exit(1);
  }
}

CuPipe::~CuPipe() {
  close(m_handles.at(READ_END));
  close(m_handles.at(WRITE_END));
}

string CuPipe::read() {
  array<char, BUFFER_SIZE> buffer;

  size_t n_bytes = ::read(m_handles[READ_END], buffer.data(),
      BUFFER_SIZE);

  if (n_bytes > 0 && n_bytes <= BUFFER_SIZE)
    return {buffer.data(), n_bytes};
  return {};
}

void CuPipe::redirect_output() {
  dup2(m_handles.at(WRITE_END), STDOUT_FILENO);
  close(m_handles.at(WRITE_END));
}

void CuPipe::redirect_input() {
  dup2(m_handles.at(READ_END), STDIN_FILENO);
  close(m_handles.at(READ_END));
}


void CuPipe::write(string message) {
  ::write(m_handles.at(WRITE_END), message.c_str(), message.size());
}

void CuPipe::close_end(int end) {
  close(m_handles.at(end));
}

int* CuPipe::get_end(int end) {
  return &m_handles.at(end);
}
