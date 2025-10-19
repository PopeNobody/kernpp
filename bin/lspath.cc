#include <syscall.hh>
#include <itr-ops.hh>
#include <vector.hh>

using sys::write;
char *getenv(const char *name, char **envp){
  size_t len=itr::len(name);
  for(size_t idx=0;envp[idx];idx++) {
    if(itr::str_cmp(envp[idx],name,len))
      continue;
    if(envp[idx][len]!='=')
      continue;
    return envp[idx]+len+1;
  };
  return 0;
};
using str::c_str;
using cont::vector_t;
char *strnewdup(const char *beg, const char *end) {
  size_t i;
  char *res=new char[end-beg+1];
  for(i=0;i<end-beg;i++){
    res[i]=beg[i];
  };
  res[i]=0;
  return res;
};
auto split(const char *beg, const char *end, char del, bool zero)
{
  int n=end-beg;
  const char *pos;
  vector_t<c_str> res;
  while(true){
    pos=itr::find_val(beg,end,del);
    if(zero || pos!=beg) {
      char *str=strnewdup(beg,pos);
      res.push_back(str);
    };
    if(pos==end)
      break;
    beg=pos+1;
  };
  return res;
};
int main(int argc, char**argv,char **envp) {
  using itr::str_cmp;
  using itr::len;
  using fmt::fmt_t;
  using str::c_str;
  c_str path=getenv("PATH",envp);
  write(2,path);
  write(2,"\n");
  auto vec=split(path.begin(),path.end(),':',false);
  size_t tot=1;
  for(auto b(vec.beg()), e(vec.end()); b!=e; b++) {
    tot+=(b->len()+1);
  };
  write(2,fmt::fmt_t(tot));
  write(2,"\n");
  char buf[tot];
  char *pos=buf;
  char *end=pos+tot-1;
  for(auto b(vec.beg()), e(vec.end()); b!=e; b++) {
    pos=itr::copy(pos,end,*b);        
    *pos++='\n';
  };
  write(1,buf,pos-buf);
  write(1,"\n");
  return 0;
};
