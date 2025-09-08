extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "new.hh"
using namespace sys;

struct string_t {
  char *_str=0;
  size_t _cap=0;
  size_t _len=0;
  string_t(const char *str="")
  {
    _len=strlen(str);
    _cap=_len;
    _str=new char[_cap+1];
    memcpy(_str,str,_len);
    _str[_len+1]=0;
  };
  ~string_t()
  {
    delete[] _str;
    memset(this,0,sizeof(*this));
  };
  char operator[](size_t pos) const {
    assert(pos<_len);
    return _str[pos];
  };
  size_t length() const {
    return _len;
  };
  const char *c_str() const {
    return _str;
  };
};
template<class T>
struct vector {
  size_t cap=0;
  size_t len=0;
  T *arr=0;
  vector(size_t cap=32)
    :cap(cap), len(0), arr((T*)new char[sizeof(T)*cap])
  {
  };
  void ensure(size_t new_cap, bool front=false)
  {
    if(new_cap >cap) {
      T *tmp=(T*)new char[sizeof(T)*cap];
      for(int i=0, j=front;i<len;i++)
        tmp[i+front]=arr[i];
      delete arr;
      arr=tmp;
      tmp=0;
    }
  };
  const T &operator[](size_t pos){
    assert(pos<len);
    return arr[pos];
  };
  size_t size() const {
    return len;
  };
  void push_back(const T &rhs){
    ensure(size()+1);
    new((void*)&arr[size()])T(rhs);
    ++len;
  };
  void push_front(const T&rhs){
    ensure(size()+1, 1);
    for(int i=0;i<size();i++) {
      arr[size()-i-1]=arr[size()-i];
    }
    new(arr)T(rhs);
  };
};
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
  string_t       d_name; /* Filename (null-terminated) */
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
  const string_t &name() const {
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
class dirent_v {
  char *names;
  vector<dirent_t> arr;
  public:
  dirent_v(size_t cap=32)
    :arr(cap)
  {
  }
  void append(const dirent_t &ent) {
    arr.push_back(ent);
  };
  size_t size() {
    return arr.size();
  };
  const dirent_t &operator[](size_t pos)
  {
    return arr[pos];
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
  char *pos=cpy(buf,ent.name().c_str(),1024);
  while(pos<buf+max)
    *pos++=' ';
  *pos++=' ';
  *pos++='|';
  *pos++=' ';
  fmt::fmt_t fino(ent.ino());
  pos=cpy(pos,fino.beg(),buf+sizeof(buf)-1-pos);
  *pos++=' ';
  *pos++='|';
  *pos++=' ';
  const char *type;
  switch(ent.type()){
    case 0: type="zero"; break;
    case 1: type="fifo"; break;
    case 2: type="cdev"; break;
    case 4: type="dir "; break;
    case 8: type="file"; break;
    default: type="???";
  };
  pos=cpy(pos,type,buf+sizeof(buf)-1-pos);
  *pos++='(';
  *pos++=' ';
  fmt::fmt_t numtype((size_t)ent.type());
  pos=cpy(pos,numtype.beg(),numtype.len());
  write(1,numtype.beg());
  write(1,fmt::fmt_t(numtype.len()));
  *pos++=' ';
  *pos++=')';
  *pos++=' ';
  *pos++='|';
  *pos++='\n';

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
    for(size_t i=0;i<ents.size();i++) {
      const dirent_t &ent=ents[i];
      if(size_t len=ent.name().length(); len>max)
        max=len;
    }
    for(size_t i=0;i<ents.size();i++) {
      const dirent_t &ent=ents[i];
      write(1,format(ent,max)); 
    }
  }
  return 0;
};
