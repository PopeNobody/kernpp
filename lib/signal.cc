#include "syscall.hh"


sigaction_t::sigaction_t()
{
  memset(this,0,sizeof(*this));
};
