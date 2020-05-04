#include <fmt.hh>
#include <syscall.hh>
#include <write_buf.hh>

using namespace fmt;
write_buf<> out(1);
write_buf<> err(2);
void fatal(const char* message, size_t len=-1)
{
  if(len < 0)
    len= strlen(message);
  write(2, message, len);
  exit(1);
}
void fatal(const char* message)
{
  fatal(message, strlen(message));
}
using namespace sys;

inline int WTERMSIG(int status) {
  return  ((status) & 0x7f);
};

inline int WIFSIGNALED(int status)
{
   return (((signed char) (((status) & 0x7f) + 1) >> 1) > 0);
};
inline int WEXITSTATUS(int status)
{
  return (((status) & 0xff00) >> 8);
};


struct bitset
{
  union {
    unsigned char data[1024/8];
    fd_set raw_set;
  };
  operator fd_set_p()
  {
    return &raw_set;
  };
  bitset()
  {
    zero();
  };
  bool get(int bit) const
  {
    return (data[bit/8] & (1<<(bit%8)))!=0;
  };
  void set(int bit)
  {
    unsigned char mask=1<<(bit%8);
    data[bit/8] |= mask;
  };
  void clr(int bit)
  {
    unsigned char mask=~(1<<(bit%8));
    data[bit/8] &= mask;
  };
  void zero()
  {
    memset(data,0,sizeof(data));
  }
  size_t max()
  {
    for(int i=1024;i;--i)
      if(get(i))
        return i;
    return -1;
  };
};
pid_t xfork()
{
  pid_t pid=fork();
  if(pid<0)
    pexit("fork");
  return pid;
};
extern "C" { 
  int main(int argc, char** argv,char**envp);
};
template<typename val_t>
val_t max(val_t lhs, val_t rhs)
{
  return lhs>rhs?lhs:rhs;
};
void show_bs(bitset &bs)
{
  bool any=false;
  out.put("bs: ").fmtln(bs.max());
  out.put("  ");
  for(int i = 0; i<16; i++)
  {
    if(bs.get(i)) {
      out.fmt(i);
      out.put(" ");
      any=true;
    };
  };
  if(!any)
    out.put("none");
  out.putln("");
  out.flush();
};
int main(int argc, char** argv,char**envp)
{
  bitset bs;
  show_bs(bs); 
  bs.set(0);
  show_bs(bs); 
  bs.set(1);
  show_bs(bs); 
  bs.set(2);
  show_bs(bs); 
  bs.clr(1);
  show_bs(bs); 
  bs.clr(0);
  show_bs(bs); 
  bs.clr(2);
  show_bs(bs); 
  return 0; 
#if 0
  if(!--argc)
    pexit("no args");
  ++argv;
  out.put("pid=").fmtln(getpid());
  const char* prog_name= *argv;
  fd_t opipe[2];
  pipe(opipe);
  fd_t epipe[2];
  pipe(epipe);
  if(!xfork())
  {
    dup2(opipe[1],1);
    dup2(epipe[1],2);
    close(opipe[0]);
    close(opipe[0]);
    execve(argv[0],argv,envp);
    abort();
  }
  
  close(opipe[1]);
  close(epipe[1]);
  bitset rset;
  rset.set(opipe[0]);
  out.put("opipe_fd=").fmtln(opipe[0]);
  out.put("epipe_fd=").fmtln(epipe[0]);
  rset.set(epipe[0]);
  bitset tmp=rset;
  int res = select(max(opipe[0],epipe[0])+1, tmp, 0, 0, 0);
  while(rset.max()) {
    tmp=rset;
    out.put("tmp.max() => ").fmtln(tmp.max());
    for(int i=0;i<10;i++) {
      if(tmp.get(i))
        out.fmtln(i);
    };
    res = select(tmp.max(), tmp, 0, 0, 0);
    if(res<0)
      pexit("select");
    out.flush();
    if(tmp.get(opipe[0]))
    {
      char ch=0;
      res=read(opipe[0],&ch,1);
      if(res==1)
        write(1,&ch,1);
      if(res==0) {
        close(opipe[0]);
        rset.clr(opipe[0]);
      };
    };
    if(tmp.get(epipe[0]))
    {
      char ch=0;
      res=read(epipe[0],&ch,1);
      if(res==1)
        write(1,&ch,1);
      if(res==0) {
        close(epipe[0]);
        rset.clr(epipe[0]);
      };
    };
    timespec ts = { 0, 10000000 };
    nanosleep(&ts,0);
  };
  return 0;
#endif
}
