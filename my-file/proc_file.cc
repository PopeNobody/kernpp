#include <debug.hh>
//   #include <syscall.hh>
#include <string.h>
#include <c_str.hh>
//   #include <errno.hh>
#include <write_buf.hh>
#include <sys/signal.h>
#include <fcntl.h>
#include <cassert>
#include <time.h>
#include <sys/mman.h>
#include <vector>

using std::vector;

#define SIGALRM 14

//   typedef void (*sighandler_t)(int);
//   sighandler_t signal(int signum, sighandler_t handler);

#define L(x) x,sizeof(x)-1

static write_buf<> err(2);
using sys::pexit;
struct pkg_t {
};

int proc_file(int fileno,const char *fn);
bool show_stats=false;
static void alarm_handler(int sig)
{
  show_stats=true;
  alarm(1);
}
int setup_alarm()
{
  sighandler_t new_handler=alarm_handler;
  sighandler_t old_handler=signal(SIGALRM,alarm_handler);
  alarm_handler(0);
};
int main(int argc, char**argv)
{
  const char * fns[] = {
"data/mirrors.evowise.com_linuxmint_packages_dists_tina_import_Contents-amd64",
"data/mirrors.evowise.com_linuxmint_packages_dists_tina_main_Contents-amd64"
  };
  debug(time(0));
  setup_alarm();
 // sys::alarm(1);
  dup2(1,2);
  if(argc>1) {
    for(int i=1;i<argc;i++)
      proc_file(i,argv[i]);
  } else {
    for(int i=0;i<sizeof(fns)/sizeof(fns[0]); i++)
      proc_file(1,fns[i]);
  };
  return 0;
};

int xopen(const char *pathname, int flags, int mode=0644 )
{
  int res=open(pathname,flags,mode);
  if(res<0)
    pexit("open",pathname);
  return res;
};
void handle_line(c_str line)
{
};
int proc_file(int fileno, const char *fn)
{
  fd_t fd = xopen(fn,O_RDONLY);
  ++fileno;
  ssize_t len=lseek(fd,0,SEEK_END);
  char *data=(char*)mmap(
      0, len, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0
      );
  time_t stime=time(0);
  char *beg=data;
  char *pos=beg;
  char *end=data+len;
  size_t lines;
  // FIXME:  we should probably check if the first line is the usual header
  //         before we skip it.
  while(pos!=end && *pos!='\n')
    ++pos;

  while(++pos!=end) {
    char *str=pos;
    while(*pos!='\n')
      ++pos;
    *pos=0;
    ++lines;
    handle_line(c_str(str,pos));
  };

  return 0;
};
