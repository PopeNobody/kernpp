#include <syscall.hh>
#include <fmt.hh>
#include <getopt.hh>


int atoi(const char *a) {
  int i=0;
  char ch;
  while(ch=*a++) {
    switch(ch) {
      case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': case '0':
        i*=10;
        i+=(ch-'0');
      default:
        write(2,"err!");
        exit(1);
    };
  };
  return i;
};
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
pair<bool,size_t> parse_int(const char *beg) {
  int res=0;
  for(char ch=*beg++;true;ch=*beg++) {
    switch (ch) {
      case '\0':
        return res;
      case '0'...'9':
        res=res*10+ch-'0';
        break;
      default:
        write(2,L("bad digit\n"));
        return 0;
    };
  };
};





#define show_val(x) do{ \
  write(2,L(#x " => ")); \
  write_dec(2,(x)); \
  write(2,L("\n")); \
}  while(false);
const char *prog_name=0;
void too_many() {
  write(2,L("too many!\n\n"));
  exit(1);
};

#define assert(x) do{if(!x)abort();}while(0)

// This is a very rough cut.
class bufferfd_t
{
  int fd;
  public:
  size_t writes;
  bufferfd_t( int fd=-1 )
    : fd(fd), writes(0)
  {
  }
  ~bufferfd_t()
  {
    flush();
    close();
  };
  void close()
  {
    sys_close(fd);
  };
  void flush()
  {
  };
  ssize_t write(const char *buf, ssize_t size)
  {
    ++writes;
    sys_write(fd, buf, size);
  };
  template<typename buf_t>
  size_t write( buf_t &buf )
  {
    ++writes;
    const char *pos=buf.pos();
    size_t len=buf.len();
    if(len > 1000){
      sys_write(2,"**\n",3);
    };
    auto res = sys_write(fd, buf.pos(), buf.len());
    return res;
  };
};
struct temp_t {
  const char * const beg;
  const char * const end;

  temp_t(const char *beg, size_t size)
    : beg(beg), end(size+beg)
  {
  };
  const char *pos() const{
    return beg;
  };
  size_t len() const{
    return end-beg;
  };
};

template<typename type>
const type &min(const type &lhs, const type &rhs)
{
  return (lhs>rhs)?rhs:lhs;
};
struct decfmt_t {
  char buf[127];
  char end[1];
  size_t npos;
  decfmt_t(size_t val)
    :npos(0)
  {
    if(!val)
      end[-(++npos)]='0';
    else while(val){
      end[-(++npos)]='0'+(val%10);
      val/=10;
    };
  };
  const char *pos() const {
    return end-npos;
  };
  size_t len() const {
    return npos;
  };
};


#if 1
int main(int argc, char**argv[]){
  bufferfd_t buf(1);
  decfmt_t fmt1(666);
  show_val(fmt1.len());
  show_val(fmt1.pos()-((char*)0));
  buf.write(fmt1);
  buf.write("\n",1);
  show_val(fmt1.len());
  buf.write(fmt1);
  buf.write("\n",1);
  fmt1=10E32;
  show_val(fmt1.len());
  buf.write(fmt1);
  buf.write("\n",1);

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
  size_t delay = 0;
  if(optind<argc) {
    delay=atoi(argv[optind++]);
    show_val(delay);
    if(!mul)
      mul=1;
    show_val(mul);
    delay*=mul;
    show_val(delay);
    exit(0);
  };
  if(optind<argc) {
    write(2,L("too many args\n"));
    return 1;
  };
  exit(0);
  show_val(opt);
  show_val(argc);
  show_val(optind);
  if(argc!=2) {
    write(2,L("Usage: usleep [microseconds]\n"));
    return 1;
  };
  timespec tm;
  unsigned long usecs=uint64_t(parse_int(argv[1]).rhs);
  tm.tv_sec=usecs/1000000;
  tm.tv_nsec=(usecs%1000000)*1000;
  write_tm(2,tm);
  write(2,L("\n"));
  int res;
  {
    // Hmmm.  I'm sure this is here for a reason.  I do need to figure 
    // these things out.  I'm thinking a lightweignt class ...
    // similar to the coming fd_t class.  As close to an int as possible,
    // but no closer.  Get all the bitwise ops looking nice.
    sigset_t sig1, sig2;
    memset(&sig1,0,sizeof(sig1));
    memset(&sig2,0,sizeof(sig2));
  };
  {
    sigaction_t act = { handler };
    act.sa_flags=0x04000000;

    //
    //So signal handlers seem to be required to send a "reset"
    //function in return, on pain of SEGV.  I just yeet the address
    //of the inline assembly function that wraps the sigreturn
    //kernel call.  I have to look into it ... what's the purpose?
    //
    act.sa_restorer=&rt_sigreturn;

    write_ptr(1,(void*)handler);
    write(1,L("\n"));
    sigaction_t old = { (void(*)(int))9 };

    res=rt_sigaction(14,&act,&old);

    write_ptr(1,(void*)old.sa_handler);
    write(1,L("\n"));

    write_dec(1,res);
    write(1,L("\n"));
  }
  while(tm.tv_sec || tm.tv_nsec) 
  {
    {
      res=alarm(1);
    }
    timespec tm2;
    res=nanosleep(&tm,&tm2);
    write_dec(1,res);
    write(1,L("\n"));
    if(!res)
      break;
    tm=tm2;
    write(1,L("tm: "));
    write_tm(1,tm);
  };
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
