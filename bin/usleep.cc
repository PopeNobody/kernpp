#include <syscall.hh>
#include <getopt.hh>


using sys::write;
using sys::nanosleep;

const static unsigned long million=1000000;
const static unsigned long billion=1000*million;
extern "C" {
  int main(int argc, char**argv, char **envp);
};
bool atoi(const char *str, long &res){
  while(*str){
    res*=10;
    res+=(*str-'0');
    str++;
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
  if(argc>3) {
    write(2,"too many args\n");
    sys::exit(1);
  } else if(argc>2) {
    atoi(argv[1],tm.tv_sec);
    atoi(argv[2],tm.tv_nsec);
  } else if(argc>1) {
    atoi(argv[1],tm.tv_nsec);
    if(tm.tv_nsec >= billion*10){
      tm.tv_sec=tm.tv_nsec/(billion*10);
      tm.tv_nsec=tm.tv_nsec%(billion*10);
    };
  } else {
    tm.tv_sec=1;
    tm.tv_nsec=0;
  };
  nanosleep(&tm,0);
  return 0;
};
