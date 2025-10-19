extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"

using namespace sys;
char **envv;

char name[256];
char *find_name(const char * const arg){
  int j=0;
  for(int i=0;arg[i];i++){
    if(arg[i]=='/'){
      j=0;
    } else {
      name[j++]=arg[i];
    };
    name[j]=0;
  };
  return name;
};
void write_array(char *const *arg, char sep, char term) {
  int i=0;
  char *beg=arg[0];
  for(i=1;arg[i];i++){
    arg[i][-1]=sep;
  };
  char *end=arg[i-1];
  while(*end)
    ++end;
  *end++=term;
  write(1,beg,end-beg); 
};
int main(int argc,char *const*argv,char *const*envp) {
  envv=(char**)envp;
  find_name(argv[0]);
  argv++;
  if(name[0]=='p') {
    write_array((char**)envp,'\n','\n');
  } else {
    write_array((char**)argv,' ','\n');
  };
  return 0;
};
using fmt::fmt_t;
struct xxx_t {
  xxx_t(){
    sys::write(1,"MAIN: ");
    sys::write(1,fmt_t((void*)&main));
    sys::write(1,"\n");
  };
  static xxx_t inst;
};
