#include "syscall.hh"
#include "fmt.hh"
void operator delete[](void *ptr) {
};
void operator delete[](void *ptr, unsigned long sz) {
};
void operator delete(void *ptr, unsigned long sz) {
};
void *malloc(unsigned long val) {
  using namespace sys;
  void *res=mmap(0,val,prot_read|prot_write,map_private|map_anon,-1,0);
  return res;
};
void *operator new[](unsigned long val) {
  return malloc(val);
}
void *operator new(unsigned long val) {
  return malloc(val);
}
