#include <string_view.hh>

extern "C" int main(int, char**);

using str::string_view;

int main(int argc, char**argv)
{
  string_view str("test");
  
  return 0;
};
