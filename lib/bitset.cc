#include "bitset.hh"

template<size_t n>
void collect::bitset_t<n>::check_bit(size_t bit)const
{
  if(bit<BITS)
    return;
  static const char ferr[]="ERROR:  bit=";
  fmt::fmt_t fBITS = BITS;
  static const char bits[]=" BITS=";
  fmt::fmt_t fbit = bit;
  static const char nl[]="\n";
  char buf[sizeof(nl)+sizeof(bits)+sizeof(ferr)+fBITS.len+fbit.len];
  char *pos=buf;
  char *end=buf+sizeof(buf)-1;
  pos=itr::copy(pos,end,ferr);
  pos=itr::copy(pos,end,fBITS);
  pos=itr::copy(pos,end,bits);
  pos=itr::copy(pos,end,fbit);
  pos=itr::copy(pos,end,nl);
  sys::write(2,buf,pos);
  std::abort();
}

collect::bitset_t<32> bs1;
collect::bitset_t<64> bs2;
collect::bitset_t<128> bs3;
collect::bitset_t<256> bs4;
collect::bitset_t<512> bs5;

void fuck() {
  bs1.check_bit(1);
  bs2.check_bit(1);
  bs3.check_bit(1);
  bs4.check_bit(1);
  bs5.check_bit(1);
};
