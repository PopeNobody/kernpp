#include <syscall.hh>
using sys::write;


template<typename itr_t>
struct range_t {
  typedef itr_t mitr_t;
  typedef const itr_t citr_t;

  typedef typeof(*mitr_t()) mref_t;
  typedef typeof(*citr_t()) cref_t;
  struct data_t {
    mitr_t b;
    mitr_t e;
    data_t(mitr_t b, mitr_t e)
      : b(b), e(e)
    {
    };
  } data;
  range_t(mitr_t b, mitr_t e)
    :data(b,e)
  {
  }
  citr_t beg() const {
    return data.b;
  };
  citr_t end() const {
    return data.e;
  };
  size_t size() const {
    return data.e-data.b;
  };

  mitr_t beg() {
    return data.b;
  };
  mitr_t end() {
    return data.e;
  };
};

int main(int argc, char**argv,char **envp) {
  typedef range_t<typeof(argv)> argv_r;
  argv_r args(argv,argv+argc);
  for(auto b(args.beg()), e(args.end()); b!=e; b++){

  };
  return 0;
};
