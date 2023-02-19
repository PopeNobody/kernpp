#include <fmt.hh>
#include <syscall.hh>
#include <getopt.hh>

using namespace fmt;
static struct option long_options[] = {
  { "number", no_argument, 0, 'n' },
  { "number-non-empty", no_argument, 0, 'b' },
  { "show-nonprinting", no_argument, 0, 'v' },
  { "show-tabs", no_argument, 0, 't' },
  { "show-ends", no_argument, 0, 'e' },
  { "show-all", no_argument, 0, 'A' },
  { 0, 0, 0, 0 },
};
#define show_val_nonl(x,y) do{ write(2,#x ": "); write_dec(2,x); y; } while(0)
#define show_val(x) show_val_nonl(x, write(2,"\n"))

template<size_t _max_size>
struct fake_array {
  typedef char *type_t;
  enum { max_size = _max_size };
  typedef type_t array_t[max_size];
  char space[sizeof(array_t)];
  size_t used;
  public:
  fake_array()
  : used(0)
  {
  }
  fake_array(const char **b, const char **e)
    :used(0)
  {
    while(b!=e)
      push_back(b);
  };
  void push_back(type_t val){
    assert(used<max_size);
    begin()[used++]=val;
  }
  type_t *begin() {
    return (type_t*)space;
  };
  type_t *end() {
    return begin()+used;
  };
  size_t size() const {
    return used;
  }
};

#define countof(x) (sizeof(x)/sizeof(x[0]))

int main(int x_argc, char** x_argv,char**x_envp)
{
  int c;
  enum { max_args=1024 };
  const char *strs[] = {
    "wtf", "-n", "/proc/mounts", "-b", "-v", "-t", "/etc/group", "-e", "-A", "--", "-n", "-b", "-v", "-t", "-e", "-A"
  };

  const char **argv=strs;
  size_t argc=countof(strs);

  write(2,"strs: "); 
  write_dec(2,countof(strs));
  write(2,"\n"); 
  write(2,argv[0]);
  for(size_t i=1;i<argc;i++){
    write(2," ");
    write(2,argv[i]);
  }
  write(2,"\n");
  

  c_str names[argc-1];
  int nnames=0;
  while(1)
  {
    int this_option_intind = optind ? optind: 1;
    int option_index=0;
    c=getopt_long(argc,(char*const*)argv,"-nbvteA",long_options,&option_index);
    switch(c) {
      case -1:
        write(2,L("neg-one\n"));
        break;
      case 0:
      case 'n':
      case 'b':
      case 'v':
      case 't':
      case 'e':
      case 'A':
        break;
      default: 
        write(2,L("unexpected option'"));
        char chs[2];
        chs[0]=c;
        chs[1]=0;
        write(2,c_str(chs,chs+1));
        write(2,"'\n");
        sys::exit(1);
    };
    if(optind==argc)
      break;
    write(2,argv[optind]);
    write(2,"\n",1);
    show_val_nonl(optind,);
    write(2," ",1);
    show_val(argc);
  };
  return 0;
}
#if 0
BusyBox v1.27.2 (Ubuntu 1:1.27.2-2ubuntu3.2) multi-call binary.

Usage: cat [-nbvteA] [FILE]...

Print FILEs to stdout

	-n	Number output lines
	-b	Number nonempty lines
	-v	Show nonprinting characters as ^x or M-x
	-t	...and tabs as ^I
	-e	...and end lines with $
	-A	Same as -vte
#endif
