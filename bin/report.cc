#include<syscall.hh>

extern "C" {
  int main(int argc, char* const* argv, char * const *envp);
};
using sys::write;
#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff00)>>8)
struct status_t {
  int res;
  bool exited() const {
    return sig()==0;
  };
  unsigned short sig() const {
    return res&0x7f;
  };
  unsigned short ret() const {
    return res/256%256;
  };
  operator int32_p() {
    return &res;
  };
};

typedef char * str_t;
typedef const char *str_c;
using sys::exit;
namespace fatal {
  inline pid_t fork() {
    pid_t res = sys::fork();
    if(res<0)
      sys::pexit("fork");
    write(2,"forked %d\n");
    return res;
  };
  inline auto wait(int *status) {
    auto pid=sys::wait(status);
    if(pid<0)
      sys::pexit("wait");
    return pid;
  };
  inline void execve(const char *argv0, char * const *argv, char * const *envp)
  {
    sys::execve(argv0,argv,envp);
    sys::pexit("execve");
  };
}
static char def_txt[]={
  "/bin/echo\0\n"
    "You neglected to give me any program to run, so I\n"
    "have enlisted echo to tell you so.  My prediction\n"
    "\n\n\0\n\n"
    "is that it will probably return zero.  but you never\n"
    "know!\n\n\0\0"
};
static char *def_cmd[3]={
  def_txt,
  def_txt,
  0
};
struct fmt_int {
  char buf[16];
  char *pos;
  const char *end() const { return buf+sizeof(buf)-1; }
  const char *beg() const { return pos; };
  fmt_int(int val)
    : buf{ "" }, pos(buf+sizeof(buf)-1)
  {
    *pos=0;
  };
};
template<class iitr, class oitr>
oitr copy( iitr ib, iitr ie, oitr &ob, oitr oe )
{
  while(true) {
    if(ib==ie)
      return ob==oe?ob:0;
    if(ob==oe)
      return 0;
    *ob++=*ib++;
  };
};
template<class itr_t>
itr_t find_end(itr_t end){
  while(*end)
    ++end;
  return end;
};
int main(int argc, char* const* argv, char * const *envp)
{
  if(!*++argv) {
    def_cmd[0]=def_txt;
    def_cmd[1]=find_end(def_cmd[0])+1;
    def_cmd[2]=find_end(def_cmd[1])+1;
    argv=(char*const*)def_cmd;
  };
  pid_t pid=fatal::fork();
  if(!pid) {
    fatal::execve(argv[0],argv,envp);
    exit(1);
  };

  status_t res;
  //     sys::sleep(10);
  fatal::wait(res);

  char *pos;
  for(pos=(char*)argv[0]; pos<argv[argc-1] || *pos; pos++)
    if(!*pos)
      *pos=' ';
  *pos++='\n';
  write(2,argv[0],pos-argv[0]);
  int num=res.sig();
  const char *desc = " returned ";
  if(num) {
    desc=" killed with ";
  } else {
    num=res.ret();
  };
  fmt_int pid_f=pid;
  fmt_int num_f=num;
  static char buf[64];
  pos=buf;
  pos=copy(pid_f.beg(), pid_f.end(), pos, buf+63);
  write(2,buf,pos-buf);  
  exit(res.res);
};
