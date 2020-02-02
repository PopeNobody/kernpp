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

template<size_t pages, size_t page_size>
void write_buf<pages,page_size>::flush()
{
  if(!pos)
    return;
  tot+=pos;
  write(fd,c_str(buf,pos));
  pos=0;
  memset(&buf,0,end-buf);
};
static write_buf<1,4096>*buf;
void doit() {
  buf->flush();
};
