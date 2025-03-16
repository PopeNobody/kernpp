#include <syscall.hh>

using namespace sys;
char **envp;
void write_strs(char **strs) {
  while(*strs){
    write(1,*strs++);
    write(1,"\n");
  };
};
int main(int argc, char**argv, char**envp){
  write(1,"ARGV:\n");
  write_strs(argv);
  write(1,"\n\nENVV:\n");
  write_strs(envp);
  return 0;
};
