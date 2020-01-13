#include <fmt.hh>
#include <syscall.hh>

using namespace fmt;
void fatal(const char *message, size_t len)
{
  if(len<0)
    len=strlen(message);
  write(2,message,len);
  exit(1);
}
void fatal(const char *message){
  fatal(message,strlen(message));
}
template <size_t size_> struct buf_t {
  enum { size = size_ };
  char buf[size - 1];
  char end[1];
  char *b() { return buf; };
  char *e() { return end; };
};
static buf_t<1024 * 10> buf;
using namespace sys;
bool catfile(int ifd, int ofd)
{
  while (true) {
    size_t rres = read(ifd, buf.buf, sizeof(buf.buf));
    if (rres == 0)
      return true;
    if (rres < 0)
      fatal(L("read error\n"));
    size_t wres=full_write(ofd, buf.buf, rres);
    if (wres !=rres)
      fatal(L("write error\n"));
  };
};

int main(int argc, char **argv) {
  const char *prog_name=*argv++;
  if (argc == 1)
    return catfile(0,1);
  int ifd=-1;
  int ofd=-1;
  while (*argv) {
    if (argv[0][0] == '-') {
      if (argv[0][1] == 0) {
        // We are catting stdin now.
        ifd = 0;
      } else if (argv[0][1] == 'o') {
        // We have a specified output file.
        char *fname=0;
        if(argv[0][2]) {
          // -ooutput.txt
          fname=&argv[0][2];
        } else if ( *++argv ) {
          // -o output.txt
          fname=*argv++;
        } else {
          fatal(L("'-o' given as last arg\n"));
        };
        sys::close(1);
        ofd = open(fname, o_creat | o_append | o_wronly,o_default);
        if(ofd<0)
          fatal(L("failed to open output file"));
      };
    } else {
      ifd = open(*argv, o_rdonly);
      if (ifd < 0) {
        write(2, L("open error\n"));
        return 1;
      };
      catfile(ifd,1);
      if(ifd)
        close(ifd);
      ++argv;
    }
  };
  close(ofd);
  return 0;
}
