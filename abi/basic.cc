#include <syscall.hh>
extern "C" {
  void *memset(void *vp, int v, size_t n){
    char *p=(char*)vp;
    for(size_t i=0;i<n;i++)
      p[i]=v;
    return p;
  };
  void *memcpy(void *vd, const void *vs, size_t n){
    const char *s=(const char *)vs;
    char *d=(char*)vd;
    if(d<s) { 
      for(int i=0;i<n;i++)
        d[i]=s[i];
    } else {
      for(int i=0;i<n;i++)
        d[n-i-1]=s[n-i-1];
    }
    return d;
  };
  char *strcpy(char *d, const char *s)
  {
    size_t i;
    for(i=0;i<strlen(s);i++) {
      d[i]=s[i];
    };
    return d+i;
  };
  size_t strlen(const char* const str){
    size_t pos=0;
    while(str[pos])
      ++pos;
    return pos;
  };

  using sys::write;
  using sys::abort;
  void __cxa_pure_virtual() { 
    write(2,L("pure virtual function called\n"));
    abort();
  }

  void __cxa_guard_release(void*)
  {
  };
  void __cxa_guard_abort(void*)
  {
  };
  void __cxa_guard_acquire(void*)
  {
  };
  void * __dso_handle=(void*)&__dso_handle;
}
