#include <syscall.hh>
#include <itr.hh>
#include <cmp.hh>
using sys::write;
using sys::full_write;
using sys::exit;
extern "C" {
  int main(int argc, char**argv, char**envp);
};

inline void die(int res, const char *msg) {
  write(2,msg);
  exit(res);
};
template<class oitr, class iitr>
oitr copy( oitr ds, oitr de, iitr ss, iitr se ) {
  while(ds!=de && ss != se)
    *ds++=*ss++;
  return ds;
};
template<class oitr, class iitr, class pred_t>
oitr copy( oitr ds, oitr de, iitr ss, pred_t pred ) {
  while(ds!=de && !pred(*ss))
    *ds++=*ss++;
  return ds;
};
template<class val_t>
class is_zero {
  bool operator()(val_t val) {
    return val==0;
  };
};
size_t write_vec_1(int fd,const char **&b, const char *d) {
  static char buffer[8*1024];
  if(!b)
    die(2,"null pointer in write_str");
  ssize_t n = 0;
  size_t dl=true_n(d);
  while(*b) {
    size_t bl=true_n(*b);
    if(dl+bl+n<n)
      break;
    if(n)
      n+=write(fd,d);
    n += write(fd,*b++);
  };
  return n;
};
inline size_t write_vec_1(int fd, char **&b, const char *d){
  return write_vec_1(fd, *(const char***)&b,d);
};
struct write_vec_t {
  int fd;
  char *pos;
  char buf[1024];
  write_vec_t(int fd)
    : fd(fd), pos(buf)
  {
    set(buf,xend(buf),0);
  };
  size_t space() const {
    return buf+sizeof(buf)-pos;
  };
  size_t write(const char *beg, const char *end=0) {
    size_t n=0;
    if(!end)
      end=beg+true_n(beg);
    size_t len=end-beg;
    if(pos>buf && pos+len>=buf+sizeof(buf)) {
      n=full_write(fd,buf,pos-buf);
      pos=buf;
      set(buf,xend(buf),0);
    };
    if(len>sizeof(buf)) {
      return n+full_write(fd,beg,true_n(beg));
    };
    char *tmp=copy(pos,buf+sizeof(buf),beg,end);
    n+=(tmp-pos);
    pos=tmp;
    return n;
  };
  size_t write(const char *beg, size_t size) {
    return write(beg,beg+size);
  };
  size_t write_vec( const char **&beg, const char *d ) {
    size_t n=0;
    if(*beg)
      n+=write(*beg++);
    while(*beg) {
      n+=write(d);
      n+=write(*beg++);
    };
    return n;
  };
  size_t write_vec( char **&ptr, const char *d ) {
    const char **tmp=(const char **)ptr;
    size_t n=write_vec(tmp,d);
    ptr=(char**)tmp;
    return n;
  };
  ~write_vec_t() {
    if(pos>buf)
      full_write(fd,buf,pos);
  };
};
const char *basename(const char *path){
  const char *pos=0;
  if(!path || !*path)
    return 0;
  const char *beg=path;
  while(*beg) {
    if(*beg++=='/')
      pos=beg;
  };
  return pos ? pos : path;
};
int main(int argc, char**argv, char **envp) {
  const char *pos=basename(*argv++);
  if(*pos) {
    write_vec_t buf(1);
    if(*pos=='e') {
      while(*argv)
        buf.write_vec(argv," ");
    } else if (*pos=='p') {
      while(*envp)
        buf.write_vec(envp,"\n");
    }
    buf.write("\n",1);
  } else {
    if(!argv || !*argv)
      die(3,"I have no identify, I don't know what to do!");
  };
  return 0;
};
