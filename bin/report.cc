#include <errno.hh>
#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>

using namespace fmt;

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


static char to_char(int num)
{
  return num+'0';
};
char env1[]="TEST1=test1";
char env2[]="TEST2=test2";
char env3[]="TEST3=test3";
char *env[]
{
  env1, env2, env3, 0
};
char **clone(char **in)
{
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
  //buf.println("arr: ",(void*)arr);
  int c=0;
  while(arr[c])
    ++c;
  return c;
};

typedef char * str_t;
typedef const char *str_c;


int main(int argc, char** argv, char **envp)
{
  if(argc<2) {
    write(2,"usage: ");
    write(2,argv[0]);
    write(2," <command>\n");
    return 2;
  };
  pid_t opid=sys::getpid();
  pid_t npid=xfork();
  int res;
  if(npid) {
    if(sys::wait(&res)<0){
      write(2,"wait: ");
      write(2,sys::strerror(sys::errno));
      write(2,"\n");
      return 1;
    };
    
    auto pos=argv;
    if(pos){
      if(*pos){
        write(2,*pos);
        while(*++pos){
          write(2," ");
          write(2,*pos);
        };
        write(2," returned ");
        write_dec(2,res);
        write(2,"\n");
        exit(res);
      };
    };
    if( wifexited(res) ) {
      res=wexitstatus(res);
      write(2,"returned ");
      write_dec(2,res);
      write(2,"\n");
      exit(res);
    } else {
      write(2,"sig: ");
      write_dec(2,wtermsig(res));
      write(2,"\n\n");
    };
  } else {
    ++argv;
    sys::execve(argv[0],argv, envp);
    return 0;
  };
  return res;
};
