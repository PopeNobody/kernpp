#pragma once
namespace getopt_ns {
  enum {
    no_argument=1,
    required_argument=2,
    optional_argument=3
  };
  struct option_t {
    char buf[256];
    int v1;
    int v2;
    int v3;
  };
  struct getopt_t {
    struct body_t {
      body_t(const char *str=0, option_t *b=0, option_t *e=0)
      {
      };
    };
    body_t body;

    getopt_t(const char *str=0, option_t *b=0, option_t *e=0)
      :body(str,b,e)
    {
    };
    template<size_t n>
      getopt_t(const char *optstr, const option_t(&a)[n])
      : body(optstr,a, a+n)
      {
      };

    int operator()(const char **argv) {
      return 0;
    };
    int operator()(char **argv) {
      return (*this)((const char**)argv);
    };
  };
}
