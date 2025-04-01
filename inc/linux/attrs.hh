#pragma once

#ifdef _NO_ALWAYS_INLINE
#define AIL
#else
#define AIL __attribute__((__always_inline__))
#endif

#ifdef _NO_NORETURN
#define NOR
#else
#define NOR  __attribute__((__noreturn__))
#endif
