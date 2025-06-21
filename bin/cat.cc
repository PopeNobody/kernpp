#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>
#include <stdlib.hh>
#include <getopt.hh>

using sys::exit;
using namespace fmt;
void fatal(const char* message, size_t len)
{
  if(len < 0)
    len= strlen(message);
  write(2, message, len);
  exit(1);
}
void fatal(const char* message)
{
  fatal(message, strlen(message));
}
template <size_t size_>
struct sbuf_t
{
  enum
  {
    size= size_
  };
  char  buf[size - 1];
  char  end[1];
  char* b()
  {
    return buf;
  };
  char* e()
  {
    return end;
  };
};
static sbuf_t<1024 * 10> buf;
using namespace sys;
bool catfile(int ifd, int ofd)
{
  while(true)
  {
    size_t rres= read(ifd, buf.buf, sizeof(buf.buf));
    if(rres == 0)
      return true;
    if(rres < 0)
      fatal(L("read error\n"));
    size_t wres= full_write(ofd, buf.buf, rres);
    if(wres != rres)
      fatal(L("write error\n"));
  };
};

extern "C" {
  int main(int argc, char**argv,char **envp);
};
const char *program_name=nullptr;
struct opts_t
{
  int num;
  int empty;
  int show_non;
  int show_tab;
  int show_end;
  opts_t()
    : num(0), empty(0), show_non(0), show_tab(0), show_end(0)
  {
  };

} opts;
using namespace getopt_ns;
static struct option_t long_options[] = {
  { "number", no_argument, 0, 'n' },
  { "number-non-empty", no_argument, 0, 'b' },
  { "show-nonprinting", no_argument, 0, 'v' },
  { "show-tabs", no_argument, 0, 't' },
  { "show-ends", no_argument, 0, 'e' },
  { "show-all", no_argument, 0, 'A' },
  { 0, 0, 0, 0 },
};
int main(int argc, char** argv,char**envp)
{
  int c;
  c_str names[argc];
  int nnames=0;
  for(int i=0;i<nnames;i++)
  {
    c_str name=names[i];
    if (name=="-") {
      catfile(0,1);
    } else {
      int fd=open(name.begin(),o_rdonly);
      if(fd<0) {
        write(2,"open:",5);
        write(2,name.begin());
        write(2,":",1);
        write_dec(2,errno);
        write(2,":",1);
        write(2,strerror(errno));
        write(2,"\n",1);
      } else {
        catfile(fd,1);
      };
    };
  };
  return 0;
}
#if 0
BusyBox v1.27.2 (Ubuntu 1:1.27.2-2ubuntu3.2) multi-call binary.

Usage: cat [-nbvteA] [FILE]...

Print FILEs to stdout

	-n	Number output lines
	-b	Number nonempty lines
	-v	Show nonprinting characters as ^x or M-x
	-t	...and tabs as ^I
	-e	...and end lines with $
	-A	Same as -vte
#endif
