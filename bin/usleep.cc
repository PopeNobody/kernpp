#include <syscall.hh>
#include <fmt.hh>
#include <getopt.hh>
#include <assert.hh>


void err_exit(const char *message){
  ssize_t res=write(2,message);
  exit(1);
};

using namespace fmt;
static void     handler(int val){
  write(2,L(__PRETTY_FUNCTION__));
  write(2,L("\n"));	
};

template<class lhs_t, class rhs_t>
struct pair {
  lhs_t lhs;
  rhs_t rhs;
  pair(const lhs_t &lhs=lhs_t(), const rhs_t &rhs=rhs_t())
    :lhs(lhs), rhs(rhs)
  {
  };
};

const char *prog_name=0;
void too_many() {
  write(2,L("too many!\n\n"));
  exit(1);
};

//
//So signal handlers seem to be required to send a "reset"
//function in return, on pain of SEGV.  I just yeet the address
//of the inline assembly function that wraps the sigreturn
//kernel call.  I have to look into it ... what's the purpose?
//
extern "C" void restorer();
asm ("restorer:mov $15,%rax\nsyscall");
#if 0
int main(int argc, char*argv[]) {
  int res=0;
  sigaction_t act = { handler };
  act.sa_flags=0x04000000;
  act.sa_restorer=&restorer;
  sigaction_t old = { (void(*)(int))9 };
  res=rt_sigaction(14,&act,&old);
  alarm(1);
  char buf[20];
  res=read(0,buf,sizeof(buf));
  return 0;
};
#else
int main(int argc, char*argv[]) {
  int opt;
  prog_name=argv[0];
  ++argv;
  --argv; 
  size_t mul=0;
  while ((opt = getopt(argc, argv, "sun")) != -1) {
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
  const static int million=1000000;
  if(optind<argc) {
    tm.tv_nsec=atoi(argv[optind++]);
    if(tm.tv_nsec >= million){
      write_tm(2,tm);write(2,L("\n"));
      tm.tv_sec=tm.tv_nsec/million;
      tm.tv_nsec=tm.tv_nsec%million;
    };
    write_tm(2,tm);write(2,L("\n"));
  };
  timespec tm2;
  nanosleep(&tm,&tm2);
//     int res;
//     {
//       sigaction_t act = { handler };
//       sigaction_t old = { handler };
//       act.sa_flags=0x04000000;
//       act.sa_restorer=&restorer;
//       res=rt_sigaction(14,&act,&old);
//       alarm(1);
//       timespec tm2;
//       res=nanosleep(&tm,&tm2);
//       write_tm(2,tm);write(2,L("\n"));
//       write_tm(2,tm2);write(2,L("\n"));
//     };
  return 0;
};
#endif

/// Hunk of man page, here for the nonce.
//  int main(int argc, char *argv[])
//  {
//    int flags, opt;
//    int nsecs, tfnd;
//    int err=0;
//  
//    nsecs = 0;
//    tfnd = 0;
//    flags = 0;
//    while ((opt = getopt(argc, argv, "hnt:")) != -1) {
//      show_val(optarg);
//      switch (opt) {
//        case 'n':
//          flags = 1;
//          break;
//        case 't':
//          nsecs = atoi(optarg);
//          tfnd = 1;
//          break;
//        default: /* '?' */
//          err=1;
//        case 'h':
//          write(2,L("Usage: "));
//          write(2,argv[0]);
//          write(2,L(" [-t nsecs] [-n] name\n"));
//          exit(err);
//      }
//    }
//  
//    show_val(flags);
//    show_val(tfnd);
//    show_val(nsecs);
//    show_val(optind);
//  
//    if (optind >= argc) {
//      write(2, "Expected argument after options\n");
//      exit(1);
//    }
//  
//    write(1,L("name argument = "));
//    write(1,argv[optind]);
//    write(1,L("\n"));
//  
//    /* Other code omitted */
//  
//    exit(1);
//  }
//  #endif
