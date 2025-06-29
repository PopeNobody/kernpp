#include <syscall.hh>
#include <search_path.hh>
#include <cmp.hh>

using namespace sys;
istr_t shell_ns::get_env(istr_t name) {
  for(istr_t *begp=environ; *begp; begp++) {
    if(cmp_ns::seq_cmp(*begp,"PATH=",5)==(0<=>0)) 
    {
      return *begp+5;
    }
  };
  return 0;
};
istr_t shell_ns::search_path(istr_t prog,istr_t name,bool deep){
  if(prog[0]=='/')
    return prog;
  istr_t s;
  char *d;
  istr_t path=get_env(name);
  ssize_t path_len=itr::len(path);
  ssize_t prog_len=itr::len(prog);
  static char *buff=0;//new char[path_len+prog_len+4];
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
