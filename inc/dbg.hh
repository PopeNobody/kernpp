#pragma once
#define NDEBUG

namespace dbg {
  struct runtime_error
  {
    struct body_t {
      const char *what;
    } body;
    runtime_error(const char *what)
      : body{what}
    {
    };
  };
  template<typename ...arg_t>
    void __xthrow(arg_t ... args);
  void __assert(const char *cond);
};

#define nop()
#define macwrap(x,y)  do{ x; y; }while(0)
#define xsrcpos() __FILE__ , ":" , __LINE__ , ":  "
#define xtrace2(x,y)  macwrap( log(xscrpos(),x,"\n");
#define xtrace(x)     xtrace2(x,nop())
#define xcomment(x)   xtrace2(x,nop())
#define xexpose(x)    xtrace2(  #x , " => " ,  x,  nop()  )
#define xcarp(x)      xtrace2(  "warning:             "      ,  x,  nop()        )
#define xcroak(x)     xtrace2(  "error:               "      ,  x,  abort()      )
#define xconfess(x)   xtrace2(  "confess:             "        x,  dump(true)   )
#define xcluck(x)     xtrace2(  "cluck:               "        x,  dump(false)  )
#define xcheckin()    xtrace2(  __PRETTY_FUNCTION__,  nop()  )
#define xassert(x)    assert(x)
#define xnv(x) #x   " => "  (x)
#define dbg() __FILE__  ":"  __LINE__  ":"
#define  xthrow(x,y) do{ dbg::__xthrow(x,y); }while(false)
//#define  xthrowre(y) xthrow(runtime_error,y)
#define  xthrowre(y) xthrow(runtime_error,y)

