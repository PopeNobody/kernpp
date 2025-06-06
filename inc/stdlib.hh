#ifndef stdlib_hh
#define stdlib_hh stdlib_hh

#include <types.hh>
extern "C"
{
  extern void*  malloc(size_t);
  extern void   free(void*);
  extern void*  realloc(void* ptr, size_t size);
  inline void*  sbrk(intptr_t increment) AIL;
  
  inline void*  memset(void* s, int c, size_t n) AIL;
  inline void*  memcpy(void* dst, const void* src, size_t n) AIL;
  inline int    memcmp(const void* dst, const void* src, size_t n) AIL;
  inline void*  memmove(void* dst, const void* src, size_t n) AIL;
  inline void*  memchr(const void* _mem, int c, size_t n) AIL;

  inline int    strcmp(const char* s1, const char* s2) AIL;
  inline char*  strcpy(char* d, const char* s) AIL;
  inline char*  strncpy(char* dst, const char* src, size_t n) AIL;
  inline char*  strncpy(char* dst, const char* src, size_t n) AIL;
  inline size_t strlen(const char* s) AIL;

  inline void*  memmove(void* _dst, const void* _src, size_t n)
  {
    char*       dst((char*)_dst);
    const char* src((const char*)_src);
    if(dst < src || dst > src + n)
      return memcpy(dst, src, n);
    while(n--)
      dst[n]= src[n];
    return dst;
  }
  inline void* memchr(const void* _mem, int c, size_t n)
  {
    const char* mem= (const char*)_mem;
    for(size_t i= 0; i < n; i++)
      if(mem[i] == c)
        return (void*)&mem[i];
    return nullptr;
  };
  inline size_t strcspn(const char* s, const char* reject)
  {
    char rej[256];
    memset(rej, 0, sizeof(rej));
    while(*reject)
      rej[*reject++]= 1;
    rej[0]  = 1;
    size_t i= 0;
    while(!rej[s[i]])
      ++i;
    return i;
  };
  inline char* strchr(const char* s, int c)
  {
    char ch;
    while((ch= *s++) != c)
    {
      if(!ch)
        return nullptr;
    }
    return (char*)s;
  };
  inline int strncmp(const char* lhs, const char* rhs, size_t n)
  {
    for(int i= 0; i < n; i++)
    {
      int res= lhs[i] - rhs[i];
      if(res)
        return res;
      if(!lhs[i])
        break;
    };
    return 0;
  };
  inline size_t strlen(const char* s)
  {
    int i;
    for(i=0;s[i];i++)
      ;
    return i;
  };
  inline int strcmp(const char* s1, const char* s2)
  {
    for(;;)
    {
      int d= *s1 - *s2;
      if(d)
        return d < 0 ? -1 : 1;
      if(!*s1)
        return 0;
      ++s1, ++s2;
    };
  };
  inline void* memset(void* s, int c, size_t n)
  {
    char* b= (char*)s;
    for(int i= 0; i < n; i++)
      b[i]= c;
    return s;
  };
  inline void* memcpy(void* dest, const void* src, size_t n)
  {
    char *d((char*)dest), *s((char*)src);
    for(int i= 0; i < n; i++)
      d[i]= s[i];
    return dest;
  };
  inline int memcmp(const void* _s1, const void* _s2, size_t n)
  {
    int         res= 0;
    const char* s1 = (const char*)_s1;
    const char* s2 = (const char*)_s2;
    for(size_t i= 0; i < n; i++)
    {
      if((res= s1[i] - s2[i]))
        break;
    };
    return res;
  };
  inline char* strcpy(char* d, const char* s)
  {
    size_t p= 0;
    for(;;)
    {
      if(not(d[p]= s[p]))
        return d;
      ++p;
    };
  };
  inline char* strncpy(char* dst, const char* src, size_t n)
  {
    size_t i;

    for(i= 0; i < n && src[i] != '\0'; i++)
      dst[i]= src[i];
    for(; i < n; i++)
      dst[i]= '\0';

    return dst;
  }
}

#endif
