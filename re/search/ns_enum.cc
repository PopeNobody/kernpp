namespace sys {
  enum open_flags
  {
    o_rdonly   = 0000,
    o_wronly   = 0001,
    o_rdwr     = 0002,
    o_mask     = 0003,
    o_creat    = 00000100,
    o_excl     = 00000200,
    o_noctty   = 00000400,
    o_trunc    = 00001000,
    o_append   = 00002000,
    o_nonblock = 00004000,
    o_dsync    = 00010000,
    o_fasync   = 00020000,
    o_direct   = 00040000,
    o_largefile= 00100000,
    o_directory= 00200000,
    o_nofollow = 00400000,
    o_noatime  = 01000000,
    o_cloexec  = 02000000,
  };
};
int main(int, char**, char**){
  using enum sys::open_flags;
  using sys::open_flags;
  open_flags flags=o_dsync;
  return 0;
};
