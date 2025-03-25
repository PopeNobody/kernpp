#include <syscall.hh>
#include <search_path.hh>
using shell_ns::search_path;
using namespace sys;
char **envp;
template<typename val_t>
void fmt(fd_t fd, val_t val);
template<>
void fmt<int>(fd_t fd, int val)
{
  static char buf[]="xxxxxxxxxxxxxxxx";
  char *end=buf+sizeof(buf)-1;
  if(val) {
    while(val) {
      *--end=(val%10)+'0';
      val/=10;
    };
  } else {
    *--end='0';
  };
  write(2,end);
};
extern istr_t *environ;
template<>
void fmt<const char*>(fd_t fd, const char * val)
{
  write(fd,val);
}
static char full[16*1024];
using shell_ns::search_path;
int main(int argc, char**argv, char**envp){
  char *path=0;
  bool abs=true;
  if(!argv[1]) {
    write(2,"No program provided\n");
    exit(2);
  };
  const char *full=0;
  full=search_path(argv[1],"PATH",false);
  if(!full) {
    write(2,"not found\n");
    exit(97);
  };
  argv++;
  pid_t pid=fork();
  pid_t res;
  if(pid) {
    int ret;
    do {
      res=waitpid(0,&ret,0);
      fmt(2,"pid ");
      fmt(2,res);
      fmt(2,"  returned ");
      fmt(2,ret);
      exit(ret/256);
    } while(res>0);
  } else {
    execve(argv[0],argv,envp);
    write(2,"execve:argv[0]");
    exit(1);
  }
  return 0;
};
