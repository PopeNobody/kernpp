#include <errno.hh>
#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>

using namespace fmt;

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

static char tab[]="0123456789abcdef";

template<size_t size>
class char_buf{
  char b[size];
  char e[1];
  char *p;
  public:
  char_buf(){
    memset(b,'.',sizeof(b));
    e[0]=0;
  };
  void put(char ch){
    *--p=ch;
  }
  void reset(){
    p=&e+1;
    put(0);
  }
  char* fmt(bool neg,unsigned long val,int radix,int width,bool nl=false)
  {
    if(nl)
      put('\n');
    while(p>b) {
      *--p=tab[val%radix];
      if(val<radix)
        break;
      val/=radix;
    }
    char *fin=e-width;
    while(p>fin)
      *--p='.';
    return p;
  }
};
char_buf<32> buf;

const char* env[]={
  "HOME=/home/nn",
    "PATH=/home/nn/bin:/usr/games:/home/nn/perl5/bin:"
    "/home/nn/.cargo/bin:/opt/bin:/usr/local/sbin:"
    "/usr/local/bin:/usr/sbin:/usr/bin:/usr/local/games",
    0
};

int main(int argc, char** argv, char **envp)
{
  if(argc<2) {
    write(2,"usage: ");
    write(2,argv[0]);
    write(2," <command>\n");
    return 2;
  };
  for(int i=0;envp[i];i++){
    write(2,envp[i]);
    write(2,"\n");
  };
  write(2,"(null)\n\n");
  
  write(2,"\n\nargc=");
  write_dec(2,argc);
  write(2,"\n\n");

  pid_t opid=sys::getpid();
  pid_t npid=sys::fork();
  int res;
  if(npid) {
    if(sys::wait(&res)<0)
      sys::pexit("wait");
    write(2,"\n\n");
    write_dec(2,res);
    write(2,"\n");
  } else {
    ++argv;
    sys::execve(argv[0],argv, envp);
    sys::pexit("execve");
  };
  sys::exit(!res);
};
