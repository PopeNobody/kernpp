#ifndef assert_hh
#define assert_hh assert_hh

void do_assert_fail(const char *file, unsigned line, const char *msg);
void do_warn_fail(const char *file, unsigned line, const char *msg,
    bool getbetter);

#define assert_fail(x) do_assert_fail(__FILE__,__LINE__,x) 
#define warn_fail(x,b) do_warn_fail(__FILE__,__LINE__,x,b)

#define assert(x) do{bool r=(x);if(!r){assert_fail(#x);};}while(0)
#define dieif(x) do{bool r=(x);if(r){warn_fail(#x,false);};}while(0)
#define warnif(x) do{bool r=(x);if(r){warn_fail(#x,true);};}while(0)


#endif
