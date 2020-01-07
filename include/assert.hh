#ifndef assert_hh
#define assert_hh assert_hh

void do_assert_fail(const char *file, unsigned line, const char *msg);

#define assert_fail(x) do_assert_fail(__FILE__,__LINE__,x) 
#define assert(x) do{auto r=(x);if(!r){assert_fail(#x);};}while(0)


#endif
