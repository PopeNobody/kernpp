#include <cstring>
void *memset(void *vp, int v, size_t n){
  char *p=(char*)vp;
  for(size_t i=0;i<n;i++)
    p[i]=v;
  return p;
};
void *memmove(void *vd, const void *vs, size_t n){
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
void *memcpy(void *vd, const void *vs, size_t n){
  return memmove(vd,vs,n);
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

