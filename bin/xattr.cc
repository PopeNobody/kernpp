#include "syscall.hh"

//ssize_t listxattr(const char *path, char *_Nullable list, size_t size);


extern "C" {
  int main(int argc, char **argv, char **envp ) {
    char buf[1024];
    using sys::write;
    size_t sz=sys::listxattr(".",buf,sizeof(buf));
    write(1,fmt::fmt_t(sz));
    write(1,"\n");
    return 0;
  }
};
