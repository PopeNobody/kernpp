#include <syscall.hh>
using namespace sys;

const char* search_path(const char *prog,const char *path){
  if(prog[0]=='/')
    return prog;
  const char *s;
  char *d;
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
  const char *p=path;
  const char *b=p;
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
