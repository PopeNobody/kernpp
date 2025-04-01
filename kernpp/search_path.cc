#include <syscall.hh>
#include <search_path.hh>

using namespace sys;
istr_t shell_ns::get_env(istr_t name) {
  for(istr_t *begp=environ; *begp; begp++) {
    if(strncmp(*begp,"PATH=",5)==0) 
    {
      return *begp+5;
    }
  };
  return 0;
};
// A deep search, like PERL5LIB, will find Term/ReadLine/Gnu.pm from
// any segment of your path.  However, a program /bin/boxer/boo will
// not be found when earching your binary path for boxer/boo, even if
// /bin is on your path.  Any slash in a shallow search requires that
// the dir be absolute, if it is the first char, or that it be rooted
// in the cwd otherwise.
istr_t shell_ns::search_path(istr_t prog,istr_t name,bool deep){
  if(prog[0]=='/')
    return prog;
  if(!deep) {
    for(istr_t pos(prog);*pos;pos++){
      if(*pos=='/')
        return prog;
    };
  };
  istr_t s;
  char *d;
  istr_t path=get_env(name);
  ssize_t path_len=strlen(path);
  ssize_t prog_len=strlen(prog);
  static char *buff=new char[path_len+prog_len+4];
  static char *ebuf=buff+path_len+prog_len+3;
  s=prog+prog_len;
  d=ebuf;
  *d--=0;
  while(s>=prog)
    *d--=*s--;
  *d--='/';
  char *r=d;
  istr_t p=path;
  istr_t b=p;
  while(*p) {
    while(*p && *p!=':')
      p++;
    s=p;
    while(s>b){
      *d--=*--s;
    }; 
    ++d;
    write(1,d);
    write(1,"\n");
    stat_t statbuf;
    if(!stat(d,&statbuf)) {
      write(1,"found at ");
      write(1,d);
      write(1,"\n");
      return d;
    };
    if(*p++) {
      b=p;
      d=r;
      continue;
    };
    write(2,"unable to find prog on path");
    exit(1);
  };
  return 0;
};
