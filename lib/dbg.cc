#include <dbg.hh>
namespace dbg 
{
  template<typename ...arg_t>
    void __xthrow(arg_t ... args)
    {
    };
  void __xassert(const char *cond)
  {
  };
}
