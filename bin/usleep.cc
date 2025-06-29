#include <syscall.hh>
#include <fmt.hh>
#include <getopt.hh>


using sys::write;
using sys::nanosleep;
using sys::exit;
using namespace fmt;
using namespace getopt_ns;

void too_many() {
  write(2,L("too many!\n\n"));
  exit(1);
};
const static int million=1000000;
const static int billion=1000*million;
getopt_t getopt(0,0,0);
extern "C" {
int main(int argc,char *const*argv,char *const*envp) {
  int opt;
  ++argv;
  --argv; 
  size_t mul=0;
  while ((opt = getopt((char**)argv)) != -1) {
    write(1,L("main: got '"));
    char ch=opt;
    write(1,&ch,1);
    write(1,L("\n"));
    switch(opt) {
      case 'n':
        if(mul)
          too_many();
        write(2,L("nanoseconds\n"));
        mul=1;
        break;


      case 'u':
        if(mul)
          too_many();
        write(2,L("microseconds\n"));
        mul=1000;
        break;

      case 's':
        if(mul)
          too_many();
        write(2,L("seconds\n"));
        mul=1000000000;
        break;


      default:
        write(2,L("bad option\n"));
        return 1;
        break;

    };
  };
  timespec tm;
//     if(getopt.ind()<argc) {
//       tm.tv_nsec=atoi(argv[getind++]);
//       if(tm.tv_nsec >= billion){
//         tm.tv_sec=tm.tv_nsec/billion;
//         tm.tv_nsec=tm.tv_nsec%billion;
//       };
//     } else {
//       tm.tv_sec=1;
//       tm.tv_nsec=0;
//     };
//     write_tm(2,tm);write(2,L("\n"));

  nanosleep(&tm,0);
  return 0;
};
};
