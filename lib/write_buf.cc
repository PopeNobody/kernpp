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
void check_print(const c_str &str)
{
//     bool err=false;
//     for(auto b(str.beg), e(str.end); b!=e; b++)
//     {
//       if(isprint(*b))
//         continue;
//       write_buf<> buf(2);
//       buf.put("you have unprintable shit in your text: ");
//       buf.fmt(int(*b));
//       buf.flush();
//       err=true;
//     };
//     if(err)
//       abort();
};
void call_write(fd_t fd, const c_str &str) {
  check_print(str);
  sys::write(fd,str.beg,str.len());
};

