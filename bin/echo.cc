#include <syscall.hh>
using sys::write;
using sys::full_write;
using sys::exit;
extern "C" {
  int main(int argc, const char**argv, const char**envp);
};
void die(int res,const char *msg) {
  write(2,msg);
  exit(res);
};
const char *basename(const char *path){
  const char *pos=0;
  if(!path || !*path)
    return 0;
  const char *beg=path;
  while(*beg) {
    if(*beg++=='/')
      pos=beg;
  };
  return pos ? pos : path;
};
void write_vec(const char **args, char sep){
  if(args[0]) {
    write(1,args[0]);
    for(int i=1;args[i];i++){
      write(1,&sep,1);
      write(1,args[i]);
    };
  };
  write(1,"\n",1);
};
int main(int argc, const char**argv, const char **envp) {
  const char *pos=basename(*argv++);
  if(*pos=='e') {
    write_vec(argv,' ');
  } else if (*pos=='p') {
    write_vec(envp,'\n');
  } else {
    die(3,"I have no identify, I don't know what to do!");
  }
  return 0;
};
