#include <errno.hh>
#include <syscall.hh>
#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff00)>>8)
namespace sys {
  ssize_t write(fd_t fd, int val)
  {
    char buf[19];
    char end[1]={0};
    char *pos=end;
    do {
      val/=10;
      *--pos='0'+val%10;
    } while(val);
    return write(fd,pos,end-pos);
  };
}
using sys::write;

int main(int argc, const char** argv, const char **envp)
{
  int res;
  if(sys::fork()) {
    if(sys::wait(&res)<0)
      sys::pexit("wait");
  } else {
    if(argv[1]) {
      ++argv;
    } else {
      static const char *args[]={ "/bin/echo", "no args passed to not", 0 };
      argv=args;
    };
    sys::execve(argv[0],(char*const*)argv, (char*const*)envp);
    sys::pexit("execve");
  };
  sys::exit(!res);
};
