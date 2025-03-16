#include <syscall.hh>

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
template<>
void fmt<const char*>(fd_t fd, const char * val)
{
  write(fd,val);
}

int main(int argc, char**argv){
  envp=argv+2;
  for(int i=0;i<argc;i++){
    write(1,argv[i],strlen(argv[i]));
    write(1,"\n",1);
  };
  envp=argv+argc;
  while(*envp)
    write(1,*envp++);
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
