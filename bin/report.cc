#include <errno.hh>
#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>
#include <typeinfo.hh>

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

#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff00)>>8)


typedef char * str_t;
typedef const char *str_c;

struct ostream_t {
  int fd;
  ostream_t(int fd)
    : fd(fd)
  {
  }
  size_t error() const {
    return -1;
  }
  size_t write(const char *beg, const char *end) const{
    size_t res=sys::write(fd,beg,end-beg);
    if(res>=0)
      return res;
    return error();
  }
};
struct sfmt_t {
  virtual ostream_t &write(ostream_t &lhs) const {
    return lhs;
  };
  sfmt_t(const char *str)
  {
  }
  sfmt_t(unsigned long val)
  {
  }
};
ostream_t out(1);
ostream_t err(2);

ostream_t &operator <<(ostream_t &lhs, const sfmt_t &rhs){
  return rhs.write(lhs);
};
const sfmt_t endl("\n");
//char empty[sizeof(sfmt_t)];
//sfmt_t *empty_cast=(sfmt_t*)empty;

extern "C" {
  char* __cxa_demangle(const char* __mangled_name, char* __output_buffer,
		 size_t* __length, int* __status)
  {
    write(2,"mangled_name: ");
    write(2,__mangled_name);
    write(2,"\n");
  };
}
int main(int argc, char** argv, char **envp)
{
  const char *mangled = typeid(endl).name();
  char demangled[1024];

  if(true){
    out << sizeof(sfmt_t) << endl;

  } else {
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
  }
  return 0;
};
