#include <syscall.hh>
#include <new.hh>
#include <fmt.hh>
#include <getopt.hh>

using sys::write;
using sys::errno;
using sys::exit;
using fmt::write_dec;
using fmt::write_ptr;
extern "C" {
  extern char *optarg;
};
namespace fmt {
  inline ssize_t write_quote(fd_t fd, int ch) {
    int res=0;
    if(ch<=32 || ch>=127) {
      res+=write(1,"(",1);
      res+=write_dec(1,ch);
      res+=write(1,")",1);
    } else {
      char str[]={'\'',(char)ch,'\'',0};
      res+=write(1,str);
    };
    return res;
  };
};
using fmt::write_quote;

static option longopts[]={
  { "version", 0, 0, 1 },
  { "help",    0, 0, 2 },
  { "date",    1, 0, 'd'},
  { "no-create", 0, 0, 'c'},
  { "no-dereference", 0, 0, 'h'}, 
  { "reference", 1, 0, 'r' },
  { "time", 1, 0, 't' },
  { 0, 0, 0, 0}
};
const char optstring[]="acdfhmr:s:t:";
#include "touch.help.inl"
int help(int res, const char *extra=0)
{
  write((res?2:1),L(help_msg));
  exit(res);
};
int version() {
  write(1,L("ls (kernpp) 1.0\n"));
  exit(0);
};
extern "C" {
  int main(int argc, char**argv, char**envp) ;
};
int touch(const char *path){
  return 0;  
};
const char *strdup(const char *str) {
  write(2,L("strdup: str="));
  write_ptr(2,str);
  write(2,L("\n"));
  return str;
};
int main(int argc, char**argv,char**envp) 
{
  int ch, longidx;
  bool opt_c, opt_h, opt_a, opt_m;
  const char *opt_d, *opt_r, *opt_t, *opt_s;
//     for(int i=0;optstring[i];i++) {
//       if(optstring[i]!=':' && ch>optstring[i]) {
//         write(2,L("\nerror: "));
//         write(2,optstring+i);
//         write(2,"\n\n",2);
//       } else {
//         write(2,optstring+i);
//         write(2,"\n");
//       };
//       if(optstring[i]!=':')
//         ch=optstring[i];
//     };
  while(true)
  {
    ch=getopt_long(argc,argv,optstring,longopts,&longidx);
    if(ch==-1) {
      write(2,L("ch==-1\n"));
      write(2,"longidx=");
      write_dec(2,longidx);
      write(2,"\n");
      break;
    };
    char chr=(char)ch;
    write(2,&chr,1);
    write(2,"\n",1);
    switch(ch) {
      case 1: return version();
      case 2: return help(0);
      case 'a': opt_a=true;
      case 'c': opt_c=true; break;
      case 'h': opt_h=true; break;
      case 'm': opt_m=true; break;
      case 'd': write_ptr(2,optarg); opt_d=strdup(optarg); break;
      case 'r': write_ptr(2,optarg); opt_r=strdup(optarg); break;
      case 't': write_ptr(2,optarg); opt_t=strdup(optarg); break;
      case 's': write_ptr(2,optarg); opt_s=strdup(optarg); break;
      case 'f': break;
      default: {
                 write(2,L("unexpected flag: "));
                 write_dec(2,ch);
                 write(2,L("\n\n"));
                 help(1);
               }
    };
  };
  if(optind>=argc){
    write(2,L("Error:  no files to touch\n\n"));
    help(2);
  };
  if(opt_d) {
    write(2,L("opt_d: "));
    write(2,opt_d);
    write(2,L("\n"));
  };
  if(opt_r) {
    write(2,L("opt_r: "));
    write(2,opt_r);
    write(2,L("\n"));
  };
  if(opt_t) {
    write(2,L("opt_t: "));
    write(2,opt_t);
    write(2,L("\n"));
  };
  for(;optind<argc;optind++){
    touch(argv[optind]);
  };
  return 0;
};


