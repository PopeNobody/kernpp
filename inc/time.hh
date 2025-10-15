#pragma once
#include "wrap.hh"
namespace std {
  typedef unsigned long uint64_t;
  typedef signed long int64_t;
  class time_t : public wrap_t<int64_t> {
    public:
    using wrap_t::wrap_t;
    using wrap_t::operator val_t&;
    using wrap_t::operator val_t;
  };
  typedef time_t *time_p;
  struct timeval_t
  {
    time_t tv_sec;
    int64_t tv_usec;
    float den() const {
      return 1000000;
    };
    timeval_t()
      : tv_sec(0), tv_usec(0)
    {
    };
    timeval_t(time_t tv_sec, int64_t tv_usec)
      : tv_sec(tv_sec), tv_usec(tv_usec)
    {
    };
    int64_t nsec() const {
      return tv_sec*den()+tv_usec*1000;
    };
  };
  struct timespec_t
  {
    time_t tv_sec;
    int64_t tv_nsec;
    float den() const {
      return 1000000000;
    };
    timespec_t()
      : tv_sec(0), tv_nsec(0)
    {
    };
    timespec_t(time_t tv_sec, int64_t tv_nsec)
      : tv_sec(tv_sec), tv_nsec(tv_nsec)
    {
    };
    int64_t nsec() const {
      return tv_sec*den()+tv_nsec;
    };
  };
  typedef timespec_t *timespec_p;
  typedef timeval_t *timeval_p;
}
using std::timespec_p;
using std::timeval_p;
using std::timespec_t;
using std::timeval_t;
using std::time_t;
using std::time_p;
