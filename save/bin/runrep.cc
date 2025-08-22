#include <syscall.hh>

using namespace sys;
char **envp;
void write_strs(char *const*strs) {
  while(*strs){
    write(1,*strs++);
    write(1,"\n");
  };
};
extern "C" {
int main(int argc,char *const*argv,char *const*envp) {
  write(1,"ARGV:\n");
  write_strs(argv);
  write(1,"\n\nENVV:\n");
  write_strs(envp);
  return 0;
};
}
