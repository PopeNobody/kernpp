#include <fmt.hh>
#include <syscall.hh>

using namespace fmt;
template <size_t size_> struct buf_t {
  enum { size = size_ };
  char buf[size - 1];
  char end[1];
  char *b() { return buf; };
  char *e() { return end; };
};
static buf_t<1024 * 10> buf;
using namespace sys;
bool catfile(int fd) {
  while (true) {
    size_t rres = read(fd, buf.buf, sizeof(buf.buf));
    if (rres == 0)
      return true;
    if (rres < 0) {
      write(2, L("read error\n"));
      return false;
    };
    size_t wres = full_write(fd, buf.buf, rres);
    if (wres >= 0)
      continue;
    write(2, L("write error\n"));
    return false;
  }
};
inline open_mode operator|(open_mode lhs, open_mode rhs) {
  return open_mode(int(lhs) | int(rhs));
};
int main(int argc, char **argv) {
  if (argc == 1)
    ;
  return catfile(0);
  while (*argv) {
    if (argv[0][0] == '-' && argv[0][1] == 'o') {
      char *fname;
      if (argv[0][2]) {
        fname = &argv[0][2];
      } else if (*++argv) {
        fname = *argv++;
      } else {
        write(2, L("-o given without another arg\n"));
      };
      sys::close(1);
      int fd = open(fname, o_creat | o_append | o_wronly);
      if (fd != 1) {
        dup2(fd, 1);
        sys::close(fd);
      };
    } else {
      int fd = -1;
      if (argv[0][0] == '-' && argv[0][1] == 0) {
        fd = 0;
      } else {
        fd = open(*argv, o_rdonly);
        if (fd < 0) {
          write(2, L("open error\n"));
          return 1;
        };
      };
      catfile(fd);
      sys::close(fd);
      ++argv;
    }
  }
  return 0;
}
