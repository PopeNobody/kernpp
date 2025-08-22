#pragma once

struct timeval
{
  time_t tv_sec;
  int64_t tv_usec;
  float den() const {
    return 1000000;
  };
  timeval(time_t tv_sec=0, int64_t tv_usec=0)
    : tv_sec(tv_sec), tv_usec(tv_usec)
  {
  };
  int64_t nsec() const {
    return tv_sec*den()+tv_usec*1000;
  };
};
struct timespec
{
  time_t tv_sec;
  int64_t tv_nsec;
  float den() const {
    return 1000000000;
  };
  timespec(time_t tv_sec=0, int64_t tv_nsec=0)
    : tv_sec(tv_sec), tv_nsec(tv_nsec)
  {
  };
  int64_t nsec() const {
    return tv_sec*den()+tv_nsec;
  };
};
typedef timespec timespec_t;
