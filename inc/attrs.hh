// we can include this as many times as we want.

#ifdef AIL
#undef AIL
#undef NOR
#else
#if 1
#define AIL __attribute__((__always_inline__))
#define NOR  __attribute__((__noreturn__))
#else
#define AIL
#endif
#endif
