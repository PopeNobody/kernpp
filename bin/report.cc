#include <errno.hh>
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
char def1[]="/bin/echo";
char def2[]="/bin/sh";
char *defs[] = { 
  def1, def2, 0
};
#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff00)>>8)

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
  1

#if 0
  do{\
    const char *cp=__PRETTY_FUNCTION__; \
    write(2,cp,strlen(cp)); \
    write(2,"\n",1); \
  } while(0)
#endif
static char to_char(int num)
{
  return num+'0';
};
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
    if(arg==0)
      arg="(null)";
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
  ssize_t write(void *ptr)
  {
    struct {
      char buf[1023];
      char end[1];
    } dat;
    char *pos=fmt_ptr(ptr,dat.buf,dat.end);
    write(pos);
    return pos-dat.buf;
  };
  ssize_t write(bool neg, unsigned long val)
  {
    struct {
      char buf[1023];
      char end[1];
    } dat;
    char *pos=fmt_dec(neg,val,dat.buf,dat.end);
    write(pos);
    return pos-dat.buf;
  };
  ssize_t println()
  {
    return write("\n");
  };
  template<typename arg0_t, typename ...argn_t>
    ssize_t println(arg0_t arg, argn_t... tail)
    {
      return print(arg,tail...,"\n");
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
char env1[]="TEST1=test1";
char env2[]="TEST2=test2";
char env3[]="TEST3=test3";
char *env[]
{
  env1, env2, env3, 0
};
char **clone(char **in)
{
  //__ent(); 
  //buf.println((void*)in);

  int c=0;
  while(in[c])
    ++c;
  char **res=new char*[c+1];
  for(int i=0;i<c;i++)
  {
    //buf.println(in[i]);
    res[i]=in[i];
  };
  res[c]=0;
  //buf.println((void*)res);
  return res;
};
int count(char**arr) 
{
  //__ent(); 
  //buf.println("arr: ",(void*)arr);
  int c=0;
  while(arr[c])
    ++c;
  return c;
};
int dump(char**arr) 
{
  __ent(); 
  buf.println("\narr: ",(void*)arr);
  int c=0;
  buf.println();
  while(arr[c])
    ++c;
  buf.println("arr.size()=",c);
  for(int i=0;i<=c;i++) {
    buf.println("arr[",i,"]=",arr[i]?arr[i]:"<null>  &=",(void*)arr[i]);
  };
  buf.println();
  return c;
};
char **d_and_c(char**arr)
{
  //__ent();
  ///int c=dump(arr);
  int c=count(arr);
  //buf.println("dump returned ", c);
  auto clo=clone(arr);
  //dump(clo);
  return clo;
};
static char **argv;
static char **envp;
int main(int argc, char** _argv, char **_envp)
{
  argv=_argv;
  envp=_envp;
  int res=0;
#if 0
  int fd=open("/dev/pts/7", sys::o_wronly);
  sys::dup2(fd,2);
  if(fd>2)
    sys::close(fd);
  __ent();
#endif

  if(argc<2) {
    buf.println("argc=",argc," need 2");
    return 2;
  };
  argv=d_and_c(argv+1);
  timespec_t dur = { 0, 100000 };
  timespec_t rem = { -1, -1 };
  envp=d_and_c(env);
  pid_t opid=sys::getpid();
  pid_t npid=xfork();
  if(npid) {
    if(sys::wait(&res)<0){
      buf.println(sys::errno,"wait:",sys::strerror(sys::errno));
      return 1;
    };
    
    if( wifexited(res) ) {
      res=wexitstatus(res);
    } else {
      buf.println("sig: ", wtermsig(res), "\n\n");
    };
    auto pos=argv;
    while(*pos){
      buf.print(*pos++," ");
    };
    buf.println("returned ",res);
  } else {
    sys::execve(argv[0],argv, envp);
    return 0;
  };
  return res;
};
