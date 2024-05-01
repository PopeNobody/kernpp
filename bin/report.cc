#include <errno.hh>
#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>
#include <buf.hh>

using namespace fmt;
extern "C" {
  int main(int argc, char**argv, char**envp);
};
#define assert(x) _assert((x),#x)
buf_ns::buf_t buf;
void _assert(bool ok, const char *cond){
  if(ok)
    return;
  buf.println("assertion failed:\n  ", cond,"\n");
  exit(1);
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
  int c=0;
  while(in[c])
    ++c;
  char **res=new char*[c+1];
  for(int i=0;i<c;i++)
  {
    res[i]=in[i];
  };
  res[c]=0;
  return res;
};
int count(char**arr) 
{
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
  static constexpr size_t n = _n;
  typedef str_t value_type;
  //typedef str_t *iterator;
  typedef str_t &reference;
  typedef str_t *pointer;
  typedef const str_t *const_pointer;
  struct lim_int {
    size_t min;
    size_t max;
    size_t val;
    lim_int(size_t min, size_t max, size_t val)
      : min(min), max(max),val(min)
    {
      set(val);
    }
    lim_int(const lim_int &copy, int val)
      : min(copy.min), max(copy.max), val(copy.min)
    {
      set(val);
    }
    void set(size_t newval) {
      assert(newval>=min && newval<=max);
      val=newval;
    };
    operator const size_t &() const {
      return val;
    };
    lim_int operator++(int) {
      lim_int res(*this);
      ++*this;
      return res;
    };
    lim_int &operator++() {
      set(val+1);
      return *this;
    };
  };
  struct iterator {
    str_list &list;
    lim_int i;
    iterator(str_list list, const lim_int &i)
      :list(list), i(i,0)
    {
      assert(i<=n);
    };
    ~iterator() {
      memset(this,0,sizeof(this));
    };
    bool operator!=(const iterator &rhs)
    {
      assert(&list==&rhs.list);
      return i!=rhs.i;
    }
    iterator operator++(int) {
      iterator res(*this);
      ++i;
      return res;
    };
    iterator &operator++() {
      assert(i<list.data.i);
      ++i;
      return *this;
    };
    str_t &operator*() {
      assert(list.data.i<n);
      while(i<list.data.i) {
        assert(list.data.i<n);
        list.push_back("");
      };
      return list[i];
    };
  };
  str_t &operator[](size_t p)
  {
    assert(p<=data.i);
    return data.list[p];
  };


  struct data_t {
    str_t list[n+1];
    lim_int i;
    data_t()
      :i(0,n,0)
    {
      memset(list,0,sizeof(list));
    };
    void push_back(const str_t &str)
    {
      if(i<n)
        list[i++]=str;
    }
    template<typename itr_t>
    void push_back(itr_t beg, itr_t end)
    {
      while(beg!=end)
        push_back(*beg++);
    };
  }data;

  str_list(str_t * const &beg, str_t * const &end)
  {
    push_back(beg,end);
  }
  template<typename itr_t>
    str_list(itr_t beg)
    {
      while(*beg)
        push_back(*beg++);
    }
  void push_back(str_c str)
  {
    assert(data.i<n);
    static int count=0;
    data.push_back((str_t)str);
  };
  void push_back(str_t str)
  {
    assert(data.i<n);
    data.push_back(str);
  };
  const_pointer end() const
  {
    assert(data.i<n);
    return &data.list[data.i];
  };
  const_pointer begin() const
  {
    assert(data.i<n);
    return &data.list[0];
  };
  iterator begin() {
    assert(data.i<n);
    return iterator(*this,lim_int(0,n,0));
  };
  iterator end() {
    assert(data.i<n);
    return iterator(*this,lim_int(0,n,size()));
  };
  template<typename itr_t>
  void push_back(itr_t beg, itr_t end)
  {
    assert(data.i<n);
    auto osize=size();
    while(beg!=end) {
      push_back(*beg++);
    };
    auto nsize=size();
    buf.println("added ", (nsize-osize), "messags");
  };
  size_t size() const
  {
    return data.i;
  };
};

int main(int argc, char** _argv, char **_envp)
{
  int res=0;
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
  timespec_t dur = { 0, 100000 };
  timespec_t rem = { -1, -1 };
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
    auto pos=argv.begin();
    while(pos!=argv.end()){
      buf.print(*pos++," ");
    };
    buf.println("returned ",res);
  } else {
    sys::execve(argv[0],argv.data.list, envp.data.list);
    buf.println("failed to exec: ", argv[0]);
    return 0;
  };
  return res;
};
