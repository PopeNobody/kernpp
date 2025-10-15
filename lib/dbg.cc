#include <dbg.hh>
namespace sys {
  void assert_fail(const char *cond, const char *file, unsigned int line)
  {
  };
};
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

}
