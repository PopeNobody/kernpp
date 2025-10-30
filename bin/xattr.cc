#include "syscall.hh"

//ssize_t listxattr(const char *path, char *_Nullable list, size_t size);


extern "C" {
  int main(int argc, char **argv, char **envp ) {
    char buf[4096];
    do {
      size_t sz=sys::listxattr(".",buf,sizeof(buf));
      if(!sz)
        break;
      sys::full_write(1,buf,sz);
    } while(1);
    return 0;
  }
};
