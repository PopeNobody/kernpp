#include <stream.hh>


stream::buf_t::buf_t()
	:_putter(*this)
{
};
void stream::fdbuf_t::__write(const str_t &str)
{
  using sys::write;
  auto b(str.beg()), e(str.end());
  while(b<e) {
    ssize_t res=write(fd,b,e-b);
    if(res<0){
      write(2,L("write failed\n"));
      abort();
    }
    b+=res;
  };
};
