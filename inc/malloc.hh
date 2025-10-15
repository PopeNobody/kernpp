#include "types.hh"

namespace std {
  void *malloc(size_t);
  void free(void *);
};
extern "C" {
  void *malloc(size_t sz);
  void free(void *vp);
};
