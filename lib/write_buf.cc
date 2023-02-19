#include <write_buf.hh>

static char isprint_chars[] = (
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO"
    "PQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
    );
class isprint_t
{
  char res[256];
  public:
  isprint_t()
  {
    memset(res,0,sizeof(res));
    for(char *pos=isprint_chars; *pos; ++pos)
    {
      res[*pos]=1;
    };
    res['\n']=1;
  };
  bool operator()(char ch) const
  {
    return res[ch];
  };
};
const isprint_t isprint;

void doit() {
  write_buf<1,4096>buf(88);
  buf.close();
  buf.flush();
};
