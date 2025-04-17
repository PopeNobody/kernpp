#include <write_buf.hh>
#include <itr.hh>
static char isprint_chars[] = (
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO"
    "PQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
    );
class isprint_t
{
  char buf[255];
  char end[1];
  public:
  isprint_t()
  {
    set(buf,end,0);
    for(char *pos=isprint_chars; *pos; ++pos)
    {
      buf[*pos]=1;
    };
    buf['\n']=1;
  };
  bool operator()(char ch) const
  {
    return buf[ch];
  };
};
const isprint_t isprint;

void doit() {
  write_buf<1,4096>buf(88);
  buf.close();
  buf.flush();
};
