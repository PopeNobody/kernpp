#include <syscall.hh>
#include <itr-ops.hh>
#include <vector.hh>

using sys::write;

int main(int argc, char**argv,char **envp) {
  using itr::str_cmp;
  using itr::len;
  using fmt::fmt_t;
  using str::c_str;
  int i;
  using cont::vector_t;
  c_str path;
  vector_t<c_str> dirs;
  {
    for(i=0;envp[i];i++) {
      if(str_cmp(envp[i],"PATH=",5)==0){
        path=envp[i]+5;
        break;
      };
    };
  };
  const char *beg=path.beg();
  char *pos=path.beg();
  const char *end=path.end();
  while(pos!=end){
    if(*pos==':') {
      *pos=0;
      c_str dir(beg,pos++);
      beg=pos;
      dirs.push_back(dir);
    };
    ++pos;
  };
  if(beg!=pos) {
    dirs.push_back(c_str(beg,pos));
  };
  for(int i=0;i<dirs.len();i++) {
    fmt_t fmt(i,10,5,' ');
    write(1,fmt);
    write(1,dirs[i]);
    write(1,"\n");
  };
  return 0;
};
