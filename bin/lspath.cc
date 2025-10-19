#include <syscall.hh>
#include <itr-ops.hh>
#include <vector.hh>

using sys::write;

char *chrdup(const char *beg, const char *end){
  size_t n=end-beg;
  char *res=new char[n];
  for(size_t i=0;i<n;i++){
    res[i]=beg[i];
  };
  return res;
};
int main(int argc, char**argv,char **envp) {
  using itr::str_cmp;
  using itr::len;
  using fmt::fmt_t;
  using str::c_str;
  int i;
  c_str path;
  {
    for(i=0;envp[i];i++) {
      if(str_cmp(envp[i],"PATH=",5)==0){
        break;
      };
    };
  };
  char *beg=envp[i]+5;
  return 0;
};
