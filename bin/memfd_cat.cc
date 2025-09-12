#include "syscall.hh"

int main(int, char**) {
  fd_t fd = memfd_create("buffer", 0);
  write(fd, "Hello, world!\n", 14);
  lseek(fd, 0, SEEK_SET);       // rewind
  dup2(fd, 0);                  // memfd becomes stdin
  execlp("cat", "cat", nullptr);  // should print "Hello, world!"
  std::abort();
};
