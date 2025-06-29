#include <syscall.hh>

extern "C" {
  using sys::write;
  using std::abort;

  void __cxa_pure_virtual() { 
    write(2,L("pure virtual function called\n"));
    abort();
  }

  void __cxa_guard_release(void*)
  {
  };
  void __cxa_guard_acquire(void*)
  {
  };
  void * __dso_handle=(void*)&__dso_handle;
  void *memcpy(char *d, char *s, size_t n){
    if(d<s) { 
      for(int i=0;i<n;i++)
        d[i]=s[i];
    } else {
      for(int i=0;i<n;i++)
        d[n-i-1]=s[n-i-1];
    }
    return d;
  };
  void memset(char *b, char v, size_t n){
    for(int i=0;i<n;i++)
      b[n]=v;
  };
}
