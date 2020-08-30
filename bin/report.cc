#include <errno.hh>
#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>
#include <buf.hh>

using namespace fmt;
extern "C" {
  int main(int argc, char**argv, char**envp);
};

buf_t buf;
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
int dump(char**arr) 
{
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
  ///int c=dump(arr);
  int c=count(arr);
  //buf.println("dump returned ", c);
  auto clo=clone(arr);
  //dump(clo);
  return clo;
};
static char **argv;
static char **envp;

template<typename itr_t, typename pred_t>
itr_t find( itr_t &beg, pred_t pred )
{
  while(true)
  {
    if(pred(*beg))
      return beg;
    ++beg;
  };
};

typedef char * str_t;
typedef const char *str_c;

template<size_t _n>
struct str_list
{
  typedef str_t value_type;
  typedef str_t *iterator;
  typedef str_t &reference;
  typedef str_t *pointer;
  typedef const str_t *const_pointer;

  static constexpr size_t n = _n;

  struct data_t {
    str_t list[n];
    size_t i;
    data_t()
    {
      memset(this,0,sizeof(*this));

    };
    template<typename itr_t>
    void push_back(itr_t beg, itr_t end)
    {
      while(beg!=end)
        list[i++]=*beg++;
    };
  }data;

  str_list(char **beg, char**end)
    :data(beg,end)
  {
    xassert(end-beg<=n);
    
    auto i=data.i;
    while(beg!=end)
      data.list[i++]=*beg++;

    size_t p(data.i);
    while(p<n)
      data.list[p++]=0;
    data.i=i;
  };
  str_list(char **beg)
    :data(beg)
  {
  };
  str_list()
  {
  };
  const_pointer end() const
  {
    return &data.list[data.i];
  };
  const_pointer begin() const
  {
    return &data.list[0];
  };
  iterator begin() {
    return &data.list[0];
  };
  iterator end() {
    return &data.list[data.i];
  };
  void push_back(const str_c str)
  {
    push_back((str_t)str);
  }; 
  void push_back(const str_t str)
  {
    data.push_back(&str,1+&str);
  };
  template<typename itr_t>
  void push_back(itr_t beg, itr_t end)
  {
    while(beg!=end)
      push_back(*beg);
  };
  size_t size() const
  {
    return data.i;
  };
};

int main(int argc, char** _argv, char **_envp)
{
  int res=0;
  str_list<20> strs;
  strs.push_back("testing");
  strs.push_back("testing");
  strs.push_back("1");
  strs.push_back("2");
  strs.push_back("3");
  for( auto str : strs )
    buf.println(str);
  strs.push_back(strs.begin(),strs.end());
#if 0
  str_list<1024> argv(_argv,_argv+argc);
  str_list<1024> envp(_envp);

  argv.push_back(".");
  for( auto str : argv )
    buf.println(str);

  buf.println(argv.size()," items");
  envp=_envp;
#if 0
  int fd=open("/dev/pts/7", sys::o_wronly);
  sys::dup2(fd,2);
  if(fd>2)
    sys::close(fd);
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
#endif
  return res;
};
