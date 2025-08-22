#include "syscall.hh"
#include "itr_ops.hh"

extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    char str1[]="abcdefghijklmno\n";
    char str2[sizeof(str1)*2];
    memcpy(str2,str1,sizeof(str1));
    sys::write(1,"aaaaaaaaaaaaaaa\n");
    sys::write(1,str2);
    sys::write(1,"aaaaaaaaaaaaaaa\n");
    memcpy(str2+5,str2,sizeof(str1));
    assert(str2[5]);
    sys::write(1,str2+5);
    sys::write(1,"aaaaaaaaaaaaaaa\n");
    memcpy(str2,str2+5,sizeof(str1));
    assert(str2[0]);
    sys::write(1,str2);
    sys::write(1,"aaaaaaaaaaaaaaa\n");
    return 0;
  }
};
