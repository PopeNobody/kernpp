#include <assert.hh>
#include <syscall.hh>
#include <fmt.hh>

using namespace fmt;
bool fatal=true;
#if 0
struct fuck_t {
  int val;
  fuck_t()
    :val(10)
  {
    write(1,L(__PRETTY_FUNCTION__));
    write(1,L("\n"));
    assert(0);
  };
};
static fuck_t fuck;
#endif
void do_assert_fail(const char *file, unsigned line, const char *msg) {
  write(2,file);
  write(2,L(":"));
  write_dec(2,line);
  write(2,L(":"));
  write(2,msg);
  write(2,L("\n\n"));
  if(fatal)
    abort();
};
void do_warn_fail(
    const char *file, unsigned line, const char *msg, bool getbetter
    )
{
  write(2,file);
  write(2,L(":"));
  write_dec(2,line);
  write(2,L(":"));
  write(2,msg);
  write(2,L("\n\n"));
  if(!getbetter)
    abort();
};


