#include <syscall.hh>
#include <new.hh>
#include <fmt.hh>
#include <getopt.hh>

using sys::write;
using sys::errno;
using sys::exit;
using fmt::write_dec;
namespace fmt {
  inline ssize_t write_quote(fd_t fd, int ch) {
    return 0;     
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
  { "time", 1, 0, 3 },
  { 0, 0, 0, 0}
};
const char optstring[]="afmt:";
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
int main(int argc, char**argv,char**envp) 
{
  int ch, longidx;
  while((ch=getopt_long(argc,argv,optstring,longopts,&longidx))!=-1)
  {
    switch(ch) {
      case 1: return version();
      case 2: return help(0);
      default: {
                 write(2,L("unexpected flag: "));
                 write_quote(2,ch);
                 write(2,"\n\n\n",3);
                 help(1);
               }
    };
  };
  if(optind>=argc){
    write(2,L("Error:  no files to touch\n\n"));
    help(2);
  };
  for(;optind<argc;optind++){
    touch(argv[optind]);
  };
  return 0;
};


