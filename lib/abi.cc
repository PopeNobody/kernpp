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
  void *memset(void *i, unsigned char v, size_t num){
    char *p((char*)i);
    for(size_t i=0;i<num;i++)
      p[i]=v;
    return i;
  };
}
