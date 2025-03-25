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
char **environ=0;
char *get_path() {
  for(char **begp=environ; *begp; begp++) {
    if(strncmp(*begp,"PATH=",5)==0) 
    {
      return *begp+5;
    }
  };
  return 0;
};
static char full[16*1024];
const char* findpath(const char *prog){
  if(prog[0]=='/')
    return prog;
  char *path=get_path();
  ssize_t start=sizeof(full)-1;
  full[start--]=0;
  ssize_t prog_len=strlen(prog);
  start-=prog_len;
  if(start<0){
    write(2,"error:  program name too long\n");
    exit(99);
  };
  memcpy(full+start,prog,prog_len);
  full[--start]='/';
  write(1,"FULL+START=");
  write(1,full+start);
  write(1,"\n",1);
  for(int p=0;path[p];p++){
    int i;
    write(1,"path+p=",path+p);
    for(i=0;path[p+i];i++){
      if(path[p+i]==':') {
        memcpy(full+start-i,path+p,i);
        write(1,full+start-i);
        write(1,"\n\n");
        break;
      };
    };
    p+=i;
  };
  return 0;
};
int main(int argc, char**argv, char**envp){
  char *path=0;
  bool abs=true;
  if(!argv[1]) {
    write(2,"No program provided\n");
    exit(2);
  };
  const char *full=0;
  environ=envp;
  full=findpath(argv[1]);
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
