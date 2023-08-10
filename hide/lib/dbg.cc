#include <dbg.hh>
namespace dbg 
{
#if 0
  struct runtime_error
  {
  };
#endif
  template<typename ...arg_t>
    void __xthrow(arg_t ... args)
    {
    };
  void __xassert(const char *cond)
  {
  };
}
