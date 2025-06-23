#include <syscall.hh>

extern "C" {
  int main(int argc, char**argv, char**envp);
};
using namespace sys;
char **envv;

size_t str_len(const char *str) {
  const char *pos=str;
  while(*pos)
    ++pos;
  return pos-str;
};
int main(int argc, char**argv, char**envp) {
  envv=envp;
  char *beg=argv[0]+str_len(argv[0])+1;
  char *end=envp[0];
  char *pos=beg;
  while(beg!=argv[0] && beg[-1]!='/')
    --beg;
  char sep=' ';
  char term='\n';
  if(*beg=='e') {
    // say nothing ... act natural
  } else if(*beg=='p') {
    pos=envp[0];
    sep='\n';
    while(*end)
      end+=(str_len(end)+1);
  } else {
    write(2,"I don't know who to be!\n");
    exit(1);
  };

  while(pos!=end) {
    if(!*pos)
      *pos=sep;
    pos++;
  }
  *--pos=term;
  write(1,beg,end-beg);
  return 0;
};
