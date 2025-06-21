extern "C" {
  int main(int, char **, char **);
};
#include "syscall.hh"
#include "c_str.hh"

using namespace sys;
void cat(const char *file) {
  int fd=open(file,o_rdonly);
  char buf[4096];
  int nr=read(fd,buf,sizeof(buf));
  if(nr<0)
    sys::pexit(3,"read");
  for(char *pos=buf;pos<buf+nr;pos++){
    int nw=write(1,pos,buf+nr-pos);
    if(nw<0)
      pexit(2,"write");
    pos+=nw;
  };
};
int main(int argc, char **argv, char **envp) {
  for(int i=1;i<argc;i++){
    cat(argv[i]);
  };
  return 0;
};

