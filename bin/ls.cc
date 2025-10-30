extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "errno.hh"
#include "new.hh"
#include "vector.hh"
#include "itr-ops.hh"
using namespace sys;

template<size_t n>
struct dirent_buf_t {
  char buf[n]={};
  size_t pos=0;
  size_t size=0;
  fd_t fd;
  dirent_buf_t(fd_t fd)
    : fd(fd)
  {
    memset(buf,0,n);
    read();
  };
  bool read() {
    pos=0;
    size=1;
    size=getdents(fd,*this,sizeof(buf));
    return !!size;
  }; 
  linux_dirent*ent(){
    if(pos>=size || pos<0) {
      return 0;
    } else {
      return (linux_dirent*)(buf+pos);
    }
  };
  operator linux_dirent*() {
    return ent();
  };
  void operator++() {
    write(2,__PRETTY_FUNCTION__);
    write(2,"\n",1);
    pos+=ent()->reclen();
    if(pos==size) {
      read();
    };
    auto *cur=ent();
    if(cur) {
      if(cur->name()[0]=='.' and cur->name()[1]=='.' and cur->name()[2]==0){
        write(1,"..\n");
        ++*this;
      } else if (cur->name()[0]=='.' && cur->name()[1]==0){
        write(1,".\n");
        ++*this;
      }
    }
  }
  void operator++(int) {
    write(2,__PRETTY_FUNCTION__);
    write(2,"\n",1);
    ++*this;
  };
};
class dirent_t {
  ino64_t        d_ino=0;    /* 64-bit inode number */
  int            d_type=-1;
  c_str       d_name; /* Filename (null-terminated) */
  public:
  dirent_t()
  {
  }
  dirent_t(const linux_dirent &rhs)
    : d_ino(rhs.ino()), d_type(rhs.type()), d_name(rhs.name())
  {
  };
  dirent_t(const char *name, ino64_t ino, char type)
    : d_ino(ino), d_type(type), d_name(name)
  {
  }
  ino64_t ino() const {
    return d_ino;
  }
  const c_str &name() const {
    return d_name;
  }
  int type() const {
    return d_type;
  };
};
template<class c1, class c2>
struct pair {
  c1 v1;
  c2 v2;
};
using cont::vector_t;

class dirent_v {
  char *names;
  vector_t<dirent_t> arr;
  public:
  dirent_v(size_t cap=32)
    :arr(cap)
  {
  }
  void append(const dirent_t &ent) {
    arr.push_back(ent);
  };
  size_t len() {
    return arr.len();
  };
  const dirent_t &operator[](size_t pos)
  {
    return *arr.get(pos);
  };
};
dirent_v read_dir(fd_t fd)
{
  dirent_buf_t<512> buf(fd);
  linux_dirent *ent=buf;
  size_t cnt=0;
  size_t cap=32;
  size_t size=cap*sizeof(dirent_t);
  dirent_v res;
  while(ent=buf) {
    while(ent=buf) {
      if(cnt==cap) {

      }
      res.append(*ent);
      buf++;
    };
  };
  return res;
}
char *cpy(char *dst, const char *src, size_t max)
{
  size_t i;
  for(i=0;i<max && src[i];i++) {
    dst[i]=src[i];
  };
  return dst+i;
}
const char *format(dirent_t ent, size_t max){
  static char buf[1024];
  char *beg(buf);
  char *end(beg+sizeof(buf));
  itr::copy(beg,end,ent.name());

  return buf;
};
char *strnewdup(const char *src){
  size_t len=strlen(src);
  char *dst=new char[len+1];
  memcpy(dst,src,len+1);
  return dst;
};
int main(int argc,char *const*argv,char *const*envp) {
  {
    dirent_t ent0("ls.cc",   0x100001,2);
    dirent_t ent1("ls.cc.ii",0x100002,2);
    dirent_t ent2("ls.cc.SS",0x100003,2);
    dirent_t ent3("ls.cc.oo",0x100004,2);
    size_t max=8;
    const char *fmt0 = strnewdup(format(ent0,8));
    const char *fmt1 = strnewdup(format(ent1,8));
    const char *fmt2 = strnewdup(format(ent2,8));
    const char *fmt3 = strnewdup(format(ent3,8));
    write(1,fmt0);
    write(1,fmt1);
    write(1,fmt2);
    write(1,fmt3);
  }

  {
    fd_t fd=open(".",o_directory|o_rdonly);
    if(fd<0)
      pexit(3,"open:.");
    dirent_v ents=read_dir(fd);
    size_t max=0;
    for(size_t i=0;i<ents.len();i++) {
      const dirent_t &ent=ents[i];
      if(size_t len=ent.name().len(); len>max)
        max=len;
    }
    for(size_t i=0;i<ents.len();i++) {
      const dirent_t &ent=ents[i];
      write(1,format(ent,max)); 
    }
  }
  return 0;
};
