#include "syscall.hh"

int main(int argc, char**argv, char**args) {
  return 0;
}
using sys::write;
using fmt::fmt_t;
namespace rc {
  struct body_t {
    uint64_t refs;
    body_t()
      : refs(1)
    {
    };
    body_t *add() {
      assert(refs>=0);
      ++refs;
      return this;
    }
    body_t *rem() {
      --refs;
      assert(refs>=0);
      return 0;
    }
    ~body_t(){
      assert(refs==0);
    };
  };

  template<class body_t>
  struct hand_t {
    rc::body_t *body;
    hand_t(rc::body_t *body=0)
      :body(0)
    {
      set(body);
    };
    ~hand_t()
    {
      set(0);
    }
    void set(rc::body_t *BODY) {
      if(body)
       body=body->rem();
      if(BODY)
        body=BODY->add();
    };
    hand_t &operator=(body_t *body){
      set(body);
      return this;
    };
  };
};
struct fdfmt_t {
  struct body_t : public rc::body_t {
    int  refs;
    fd_t fd;
    char buf[1024];
    body_t(fd_t fd)
      : refs{1},fd{2},buf{}
    {
    };
    body_t *add() 
    {
      ++refs;
      return this;
    };
  };
  static body_t *single() {
    static body_t single(2);
    return &single;
  };
  struct hand_t : public rc::hand_t<body_t> {
  } body;
  fdfmt_t()
    :body(single())
  {
  };
};
fdfmt_t err;
extern "C" {
  size_t len(const char * const a){
    const char *p(a);
    while(*p)
      p++;
    return p-a;
  };
ssize_t write(fd_t fd, const char *a1, const char *a2, fmt_t a3){
  ssize_t res=0;
  res+=write(fd,a1);
  res+=write(fd,a2);
  res+=write(fd,a3);
  res+=write(fd,"\n\n");
  return res;
};
#define show(x) write(2, #x, " => ", fmt::fmt_t(x))
  void call_main(char *args[]) {
    int i=0;
    uint64_t argc=(uint64_t)args[0];
    char **argv=++args;
    while(*args)
      ++args;
    char **envp=++args;

    show(argc);
    show((void*)argv);
    show((void*)envp);
    using str::c_str;
    show(c_str(argv[0]));
    show(c_str(envp[0]));

  };
};
