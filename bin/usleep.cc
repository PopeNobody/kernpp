#include <syscall.hh>
#include <getopt.hh>


using sys::write;
using sys::nanosleep;

void too_many() {
  write(2,L("too many!\n\n"));
  sys::exit(1);
};
const static int million=1000000;
const static int billion=1000*million;
extern "C" {
  int main(int argc, char**argv, char **envp);
};
bool atoi(const char *str){
  long res=0;
  while(*str){
    res*=10;
    res+=(*str-'0');
  };
  return res;
};
int main(int argc, char**argv, char **envp)
{
  int opt;
  ++argv;
  --argv; 
  size_t mul=0;
  timespec tm;
  if(argc>2) {
    write(2,"too many args");
  } else if(argc>1) {
    tm.tv_nsec=atoi(argv[1]);
    if(tm.tv_nsec >= billion){
      tm.tv_sec=tm.tv_nsec/billion;
      tm.tv_nsec=tm.tv_nsec%billion;
    };
  } else {
    tm.tv_sec=1;
    tm.tv_nsec=0;
  };
  nanosleep(&tm,0);
  return 0;
};
