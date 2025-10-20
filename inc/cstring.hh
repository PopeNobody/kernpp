extern "C" {
  typedef unsigned long size_t;
  void *memcpy(void *d, const void *s, size_t n);
  void *memmove(void *d, const void *s, size_t n);
  void *memset(void *b, int v, size_t n);
  size_t strlen(const char *);
  char*strcpy(char *d, const char *s);
  char*strcat(char *d, const char *s);
}
