#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>

using namespace fmt;
extern "C" {
  int main(int argc, char**argv, char**envp);
};
// int execve(const char * fn, char *const * argv, char *const * envp)
pid_t xfork()
{
  pid_t pid=sys::fork();
  if(pid<0) {
    sys::write(1,"fork:",5);
    sys::write(1,"wtf?",4);
    exit(1);
  };
  return pid;
};
const char *defs[] = { "/bin/sh", 0};
#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff)>>8)

void __xassert(const char *cont, bool val)
{
  if(val)
    return;
  write(2,"assert fail:\n'");
  write(2,cont);
  write(2,"'\n");
  asm("int3");
};

#define xassert(x) __xassert(#x,(x))

#define __ent() \
  do{\
    const char *cp=__PRETTY_FUNCTION__; \
    write(2,cp,strlen(cp)); \
    write(2,"\n",1); \
  } while(0)
struct buf_t {
  char text[8*1024];
  size_t len;
  buf_t()
    : text(""), len(0)
  {
  };
  ssize_t __write(const char *text, ssize_t len)
  {
    xassert(len>=0);
    sys::write(1,text,len);
    return 0;
  };
  ssize_t write(const char *arg)
  {
    return __write(arg,strlen(arg));
  };
  ssize_t write(char &arg)
  {
    return __write(&arg,1);
  };
  ssize_t write(int arg)
  {
    if(arg<0)
      return write(true,arg);
    else
      return write(false,arg);
  };
  ssize_t write(bool neg, unsigned long val)
  {
    char buf[128];
    char *end=buf+sizeof(buf);
    *--end='\n';
    char *pos=end;
    *--pos=0;
    for(int i=0;i<sizeof(val);i++)
      *--pos=val%10, val/=10;
    write(pos);
    return end-pos;
  };
  ssize_t println()
  {
    return 0;
  };
  template<typename arg0_t, typename ...argn_t>
    ssize_t println(arg0_t arg, argn_t... tail)
    {
      return write(arg)+print(tail...,"\n");
    };
  ssize_t print()
  {
    return 0;
  };
  template<typename arg0_t, typename ...argn_t>
    ssize_t print(arg0_t arg, argn_t... tail)
    {
      return write(arg)+print(tail...);
    };
} buf;
int main(int argc, char** argv, char **envp)
{
  int fd=open("/dev/pts/7", sys::o_wronly);
  sys::dup2(fd,1);
  sys::dup2(fd,2);
  if(fd>2)
    sys::close(fd);
    
  buf_t buf;
  pid_t pid=xfork();
  buf.println("pid: ",pid);
  timespec_t dur = { 0, 10000 };
  timespec_t rem = { -1, -1 };
  if(pid) {
    asm("int3");
    buf.println("waiting");
    int res=-1;
    pid_t pid2=sys::wait(&res);
    buf_t buf;
    if( wifexited(res) ) {
      int stat=wexitstatus(res);
      buf.println("code: ", stat);
      res=stat;
    } else {
      buf.println("sig: ", wtermsig(res));
    };
    exit(res);
  } else {
    if(argc>=1) {
      ++argv; --argc;
      sys::execve(argv[0],argv,envp);
    } else {
      sys::execve(defs[0],(char*const*)defs, envp);
    };
  };
  return 0;
};
